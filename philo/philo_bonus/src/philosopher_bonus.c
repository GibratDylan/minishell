/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:17:48 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:34:11 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	check_philo_is_dead(t_philo *philo)
{
	if ((get_clock(philo->start_clock)
			- philo->time_last_eat) >= philo->attr->time_to_die)
		return (1);
	return (0);
}

int	check_philo_eat_enough(t_philo *philo)
{
	if (philo->nb_eat == philo->attr->eat_before_end)
		return (1);
	return (0);
}

static void	*signal_handler(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sem_wait(philo->kill_signal);
	modify_stop(philo, 1);
	return (NULL);
}

static int	philosopher_status(t_philo *philo)
{
	if (get_stop(philo) == 0)
		take_fork(philo);
	if (get_stop(philo) == 1)
		return (1);
	if (check_philo_is_dead(philo))
	{
		sem_wait(philo->print_sem);
		sem_post(philo->is_dead);
		if (!get_stop(philo))
		{
			usleep(1000);
			printf("%i %i is dead\n", get_clock(philo->start_clock),
				philo->index + 1);
		}
		sem_post(philo->print_sem);
		modify_stop(philo, 1);
		return (1);
	}
	if (check_philo_eat_enough(philo))
	{
		modify_stop(philo, 1);
		sem_post(philo->is_eat_enough);
		return (1);
	}
	return (0);
}

void	philosopher(t_philo *philo)
{
	pthread_t	signal;
	pthread_t	clock;

	philo->time_last_eat = 0;
	pthread_create(&signal, NULL, signal_handler, philo);
	pthread_create(&clock, NULL, while_check_philo_is_dead, philo);
	if ((philo->index + 1) % 2)
	{
		if (philo->attr->time_to_die * 1000 < philo->attr->time_to_eat)
			usleep(philo->attr->time_to_die * 1000);
		else
			usleep(philo->attr->time_to_eat);
	}
	while (1)
	{
		if (philosopher_status(philo))
		{
			pthread_join(signal, NULL);
			pthread_join(clock, NULL);
			return ;
		}
		usleep(1000);
	}
}

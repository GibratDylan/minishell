/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:17:48 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/01 18:51:00 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	check_philo_is_dead(t_philo *philo)
{
	if ((get_clock(philo->start_clock)
			- philo->time_last_eat) > philo->attr->time_to_die)
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

void	philosopher(t_philo *philo)
{
	struct timeval	timestamp;
	pthread_t		signal;

	philo->time_last_eat = 0;
	gettimeofday(&timestamp, NULL);
	pthread_create(&signal, NULL, signal_handler, philo);
	philo->start_clock = timestamp.tv_sec * 1000 + (timestamp.tv_usec / 1000);
	if ((philo->index + 1) % 2)
	{
		if (philo->attr->time_to_die * 1000 < philo->attr->time_to_eat)
			usleep(philo->attr->time_to_die * 1000);
		else
			usleep(philo->attr->time_to_eat);
	}
	while (1)
	{
		if (check_philo_is_dead(philo))
		{
			printf("%i %i is dead\n", get_clock(philo->start_clock),
				philo->index + 1);
			modify_stop(philo, 1);
			sem_post(philo->is_dead);
			pthread_join(signal, NULL);
			return ;
		}
		if (get_stop(philo) == 0)
			take_fork(philo);
		if (check_philo_eat_enough(philo))
		{
			printf("%i %i has eaten enough\n", get_clock(philo->start_clock),
				philo->index + 1);
			modify_stop(philo, 1);
			sem_post(philo->is_eat_enough);
			pthread_join(signal, NULL);
			return ;
		}
		if (get_stop(philo) == 1)
		{
			pthread_join(signal, NULL);
			return ;
		}
		usleep(10);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:47:09 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/01 18:51:50 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	*pthread_with_wait_is_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sem_wait(philo->is_dead);
	modify_stop(philo, 1);
	return (NULL);
}

static void	*pthread_with_wait_is_eat_enough(void *arg)
{
	t_arg	*arg_s;
	int		i;

	arg_s = (t_arg *)arg;
	i = 0;
	while (i < arg_s->nb_of_philo)
	{
		sem_wait(arg_s->philo->is_eat_enough);
		i++;
	}
	modify_stop(arg_s->philo, 1);
	return (NULL);
}

void	wait_process_end(t_philo **philo, int nb_of_philos)
{
	pthread_t	thread;
	t_arg		arg;

	arg.nb_of_philo = nb_of_philos;
	arg.philo = philo[0];
	pthread_create(&thread, NULL, pthread_with_wait_is_dead, philo[0]);
	philo[0]->wait_dead_thread = thread;
	pthread_create(&thread, NULL, pthread_with_wait_is_eat_enough, &arg);
	philo[0]->wait_eat_thread = thread;
	if (nb_of_philos == 1)
	{
		usleep((philo[0]->attr->time_to_die * 1000) + 5000);
		sem_post(philo[0]->fork_sem);
	}
	while (1)
	{
		if (get_stop(philo[0]))
		{
			close_all_philos(philo, nb_of_philos);
			return ;
		}
		usleep(100);
	}
}

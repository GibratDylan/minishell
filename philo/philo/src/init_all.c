/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:11:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 15:20:23 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_all_philos(int i, t_attr *attr, t_clock *clock, t_philo ***all_philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*prev_fork;
	pthread_mutex_t	*first_fork;
	char			*philos_state;

	*all_philo = ft_malloc(i, sizeof(t_philo *));
	prev_fork = init_fork();
	philos_state = ft_malloc(i, sizeof(char));
	if (!(*all_philo) || !prev_fork || !philos_state)
		return (1);
	(ft_memset(philos_state, THINK, i--), first_fork = prev_fork);
	while (i)
	{
		right_fork = init_fork();
		(*all_philo)[i] = init_philo(i, prev_fork, right_fork,
				&philos_state[i]);
		if (!((*all_philo)[i]) || !right_fork)
			return (1);
		set_attr_clock_philo((*all_philo)[i--], clock, attr);
		prev_fork = right_fork;
	}
	(*all_philo)[i] = init_philo(i, prev_fork, first_fork, &philos_state[i]);
	if (!((*all_philo)[i]))
		return (1);
	return (set_attr_clock_philo((*all_philo)[i], clock, attr), 0);
}

int	launch_philo_threads(t_philo **all_philo, int count)
{
	pthread_t	*philo_thread;
	int			i;

	i = 0;
	while (i < count)
	{
		philo_thread = ft_malloc(1, sizeof(pthread_t));
		if (!philo_thread)
			return (1);
		if (pthread_create(philo_thread, NULL, philosopher, all_philo[i]))
			return (1);
		all_philo[i]->thread_philo = philo_thread;
		i++;
	}
	return (0);
}

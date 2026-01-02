/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:09:04 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:33:57 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	get_clock(int start)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * 1000 + (timestamp.tv_usec / 1000)) - start);
}

void	*while_check_philo_is_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if ((get_clock(philo->start_clock)
				- philo->time_last_eat) >= philo->attr->time_to_die)
		{
			sem_post(philo->fork_sem);
			return (NULL);
		}
		if (get_stop(philo) == 1)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

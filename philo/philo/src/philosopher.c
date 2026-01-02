/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:17:48 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 19:24:18 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	modify_time_last_eat(philo->state_mutex, &(philo->time_last_eat),
		get_clock(philo->clock->clock_mutex, philo->clock->clock_value));
	if ((philo->index + 1) % 2)
	{
		if (philo->attr->time_to_die * 1000 < philo->attr->time_to_eat)
			usleep(philo->attr->time_to_die * 1000);
		else
			usleep(philo->attr->time_to_eat);
	}
	while (1)
	{
		if (get_state(philo->state_mutex, philo->state) == DEAD)
			return (NULL);
		if (get_state(philo->state_mutex, philo->state) == THINK)
			take_fork(philo);
		usleep(1000);
	}
	return (NULL);
}

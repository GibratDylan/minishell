/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:39:20 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 14:21:31 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	action_eat(t_philo *philo)
{
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (unlock_first_forks(philo), unlock_second_forks(philo), 1);
	modify_state(philo->state_mutex, philo->state, EAT);
	modify_time_last_eat(philo->state_mutex, &(philo->time_last_eat),
		get_clock(philo->clock->clock_mutex, philo->clock->clock_value));
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (unlock_first_forks(philo), unlock_second_forks(philo), 1);
	if (printf("%i %i is eating\n", get_clock(philo->clock->clock_mutex,
				philo->clock->clock_value), philo->index + 1) == -1)
		return (modify_state(philo->state_mutex, philo->state, DEAD),
			unlock_first_forks(philo), unlock_second_forks(philo), 1);
	add_nb_eat(philo->nb_eat_mutex, &(philo->nb_eat));
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (unlock_first_forks(philo), unlock_second_forks(philo), 1);
	usleep(philo->attr->time_to_eat);
	return (0);
}

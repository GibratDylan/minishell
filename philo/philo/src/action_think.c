/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:43:46 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 14:24:22 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	action_think(t_philo *philo)
{
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (1);
	if (printf("%i %i is thinking\n", get_clock(philo->clock->clock_mutex,
				philo->clock->clock_value), philo->index + 1) == -1)
		return (modify_state(philo->state_mutex, philo->state, DEAD), 1);
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (1);
	modify_state(philo->state_mutex, philo->state, THINK);
	return (0);
}

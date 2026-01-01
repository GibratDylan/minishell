/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:41:41 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/01 18:11:11 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	action_sleep(t_philo *philo)
{
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	if (printf("%i %i is sleeping\n", get_clock(philo->start_clock),
			philo->index + 1) == -1)
		return (1);
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	usleep(philo->attr->time_to_sleep);
	return (0);
}

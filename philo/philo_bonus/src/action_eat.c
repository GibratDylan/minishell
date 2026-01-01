/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:39:20 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/01 18:10:48 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	action_eat(t_philo *philo)
{
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	philo->time_last_eat = get_clock(philo->start_clock);
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	if (printf("%i %i is eating\n", get_clock(philo->start_clock), philo->index
			+ 1) == -1)
		return (1);
	philo->nb_eat++;
	if (get_stop(philo) || check_philo_is_dead(philo))
		return (1);
	usleep(philo->attr->time_to_eat);
	return (0);
}

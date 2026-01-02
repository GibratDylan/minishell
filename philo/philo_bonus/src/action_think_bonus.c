/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:43:46 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:30:38 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	action_think(t_philo *philo)
{
	sem_wait(philo->print_sem);
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (sem_post(philo->print_sem), 1);
	if (printf("%i %i is thinking\n", get_clock(philo->start_clock),
			philo->index + 1) == -1)
		return (sem_post(philo->print_sem), 1);
	sem_post(philo->print_sem);
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	return (0);
}

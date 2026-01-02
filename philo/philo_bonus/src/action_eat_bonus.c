/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:39:20 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:30:42 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	action_eat(t_philo *philo)
{
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	sem_wait(philo->print_sem);
	if (get_stop(philo) || check_philo_eat_enough(philo)
		|| check_philo_is_dead(philo))
		return (sem_post(philo->print_sem), 1);
	philo->time_last_eat = get_clock(philo->start_clock);
	if (printf("%i %i is eating\n", get_clock(philo->start_clock), philo->index
			+ 1) == -1)
		return (sem_post(philo->print_sem), 1);
	sem_post(philo->print_sem);
	philo->nb_eat++;
	if (get_stop(philo) || check_philo_is_dead(philo))
		return (1);
	usleep(philo->attr->time_to_eat);
	return (0);
}

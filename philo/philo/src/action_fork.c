/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:23:47 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 14:33:45 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	lock_first_fork(t_philo *philo)
{
	if (philo->right_fork > philo->left_fork)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (unlock_first_forks(philo), 1);
	if (printf("%i %i has taken a fork\n", get_clock(philo->clock->clock_mutex,
				philo->clock->clock_value), philo->index + 1) == -1)
		return (modify_state(philo->state_mutex, philo->state, DEAD),
			unlock_first_forks(philo), 1);
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (unlock_first_forks(philo), 1);
	modify_state(philo->state_mutex, philo->state, FORK);
	return (0);
}

int	lock_second_fork(t_philo *philo)
{
	if (philo->right_fork < philo->left_fork)
		pthread_mutex_lock(philo->left_fork);
	else if (philo->right_fork == philo->left_fork)
		return (unlock_first_forks(philo), 1);
	else
		pthread_mutex_lock(philo->right_fork);
	if (get_state(philo->state_mutex, philo->state) == DEAD)
		return (unlock_first_forks(philo), unlock_second_forks(philo), 1);
	if (printf("%i %i has taken a fork\n", get_clock(philo->clock->clock_mutex,
				philo->clock->clock_value), philo->index + 1) == -1)
		return (modify_state(philo->state_mutex, philo->state, DEAD),
			unlock_first_forks(philo), unlock_second_forks(philo), 1);
	return (0);
}

int	unlock_first_forks(t_philo *philo)
{
	if (philo->right_fork > philo->left_fork)
		pthread_mutex_unlock(philo->left_fork);
	else
		pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	unlock_second_forks(t_philo *philo)
{
	if (philo->right_fork > philo->left_fork)
		pthread_mutex_unlock(philo->right_fork);
	else
		pthread_mutex_unlock(philo->left_fork);
	return (0);
}

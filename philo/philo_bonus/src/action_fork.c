/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:23:47 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/01 18:49:01 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	lock_first_fork(t_philo *philo)
{
	sem_wait(philo->fork_sem);
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	if (printf("%i %i has taken a fork\n", get_clock(philo->start_clock),
			philo->index + 1) == -1)
		return (1);
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	return (0);
}

int	lock_second_fork(t_philo *philo)
{
	int	i;

	sem_getvalue(philo->fork_sem, &i);
	sem_wait(philo->fork_sem);
	if (get_stop(philo) || check_philo_is_dead(philo)
		|| check_philo_eat_enough(philo))
		return (1);
	if (printf("%i %i has taken a fork\n", get_clock(philo->start_clock),
			philo->index + 1) == -1)
		return (1);
	return (0);
}

int	unlock_first_forks(t_philo *philo)
{
	sem_post(philo->fork_sem);
	return (0);
}

int	unlock_second_forks(t_philo *philo)
{
	sem_post(philo->fork_sem);
	return (0);
}

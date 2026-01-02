/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:05:34 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:34:13 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	take_fork(t_philo *philo)
{
	if (lock_first_fork(philo))
		return ;
	if (lock_second_fork(philo))
		return ;
	if (action_eat(philo))
		return ;
	unlock_first_forks(philo);
	unlock_second_forks(philo);
	if (action_sleep(philo))
		return ;
	if (action_think(philo))
		return ;
	return ;
}

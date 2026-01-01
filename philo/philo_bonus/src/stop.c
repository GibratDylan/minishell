/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:03:28 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/01 18:13:35 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	get_stop(t_philo *philo)
{
	int	result;

	sem_wait(philo->stop_sem);
	result = philo->stop;
	sem_post(philo->stop_sem);
	return (result);
}

void	modify_stop(t_philo *philo, int new)
{
	sem_wait(philo->stop_sem);
	philo->stop = new;
	sem_post(philo->stop_sem);
}

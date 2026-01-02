/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_philos_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:41:32 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:33:59 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	close_all_philos(t_philo **all_philo, int nb_of_philo)
{
	int	i;

	i = 0;
	while (i < nb_of_philo)
	{
		sem_post(all_philo[i]->kill_signal);
		sem_post(all_philo[i]->is_dead);
		sem_post(all_philo[i]->is_eat_enough);
		sem_post(all_philo[i]->fork_sem);
		i++;
	}
	pthread_join(all_philo[0]->wait_dead_thread, NULL);
	pthread_join(all_philo[0]->wait_eat_thread, NULL);
	i = 0;
	while (i < nb_of_philo)
	{
		waitpid(all_philo[i]->pid, NULL, 0);
		i++;
	}
}

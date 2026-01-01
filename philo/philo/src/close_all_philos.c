/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:41:32 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 15:31:45 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	close_all_philos(t_philo **all_philo, int nb_of_philo)
{
	int	i;

	i = 0;
	while (i < nb_of_philo)
	{
		modify_state(all_philo[i]->state_mutex, all_philo[i]->state, 'D');
		i++;
	}
	i = 0;
	while (i < nb_of_philo)
	{
		pthread_join(*(all_philo[i]->thread_philo), NULL);
		i++;
	}
	i = 0;
	while (i < nb_of_philo)
	{
		pthread_mutex_destroy(all_philo[i]->state_mutex);
		pthread_mutex_destroy(all_philo[i]->right_fork);
		i++;
	}
}

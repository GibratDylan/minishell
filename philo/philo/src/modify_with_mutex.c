/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_with_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:10:29 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 14:39:49 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	modify_state(pthread_mutex_t *mutex, char *state, char new_state)
{
	pthread_mutex_lock(mutex);
	*state = new_state;
	pthread_mutex_unlock(mutex);
}

void	modify_time_last_eat(pthread_mutex_t *mutex, int *time_last_eat,
		int new)
{
	pthread_mutex_lock(mutex);
	*time_last_eat = new;
	pthread_mutex_unlock(mutex);
}

void	modify_clock_value(pthread_mutex_t *mutex, int *clock_value, int new)
{
	pthread_mutex_lock(mutex);
	*clock_value = new;
	pthread_mutex_unlock(mutex);
}

void	add_nb_eat(pthread_mutex_t *mutex, int *nb_eat)
{
	pthread_mutex_lock(mutex);
	(*nb_eat)++;
	pthread_mutex_unlock(mutex);
}

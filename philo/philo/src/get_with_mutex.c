/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_with_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:09:04 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 14:39:40 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	get_last_time_eat(pthread_mutex_t *mutex, int *time_last_eat)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *time_last_eat;
	pthread_mutex_unlock(mutex);
	return (result);
}

int	get_clock(pthread_mutex_t *mutex, int *clock)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *clock;
	pthread_mutex_unlock(mutex);
	return (result);
}

char	get_state(pthread_mutex_t *mutex, char *state)
{
	char	result;

	pthread_mutex_lock(mutex);
	result = *state;
	pthread_mutex_unlock(mutex);
	return (result);
}

int	get_nb_eat(pthread_mutex_t *mutex, int *nb_eat)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *nb_eat;
	pthread_mutex_unlock(mutex);
	return (result);
}

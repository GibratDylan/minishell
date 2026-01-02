/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 01:23:46 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 14:02:27 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_clock	*init_clock(void)
{
	int				*clock_value;
	pthread_mutex_t	*clock_mutex;
	t_clock			*clock;

	clock = ft_malloc(1, sizeof(t_clock));
	clock_value = ft_malloc(1, sizeof(int));
	if (!clock || !clock_value)
		return (NULL);
	*clock_value = 0;
	clock->clock_value = clock_value;
	clock_mutex = ft_malloc(1, sizeof(pthread_mutex_t));
	if (!clock_mutex)
		return (NULL);
	if (pthread_mutex_init(clock_mutex, NULL))
		return (NULL);
	clock->clock_mutex = clock_mutex;
	return (clock);
}

void	*ft_clock(void *arg)
{
	struct timeval	timestamp;
	int				start;
	t_clock			*clock;

	clock = (t_clock *)arg;
	gettimeofday(&timestamp, NULL);
	start = timestamp.tv_sec * 1000 + (timestamp.tv_usec / 1000);
	while (1)
	{
		gettimeofday(&timestamp, NULL);
		if (get_clock(clock->clock_mutex, clock->clock_value) == -1)
			return (NULL);
		if (get_clock(clock->clock_mutex, clock->clock_value) != -1)
			modify_clock_value(clock->clock_mutex, clock->clock_value,
				(timestamp.tv_sec * 1000 + (timestamp.tv_usec / 1000)) - start);
		if (get_clock(clock->clock_mutex, clock->clock_value) == -1)
			return (NULL);
		usleep(500);
	}
}

void	terminate_clock(t_clock *clock, pthread_t clock_thread)
{
	modify_clock_value(clock->clock_mutex, clock->clock_value, -1);
	pthread_join(clock_thread, NULL);
	pthread_mutex_destroy(clock->clock_mutex);
}

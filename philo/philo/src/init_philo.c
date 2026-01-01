/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:02:29 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/31 10:24:56 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*init_philo(int index, pthread_mutex_t *prev_fork,
		pthread_mutex_t *right_fork, char *state)
{
	t_philo			*philo;
	pthread_mutex_t	*state_mutex;
	pthread_mutex_t	*nb_eat_mutex;

	philo = ft_malloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->left_fork = prev_fork;
	philo->right_fork = right_fork;
	philo->index = index;
	philo->state = state;
	state_mutex = ft_malloc(1, sizeof(pthread_mutex_t));
	if (!state_mutex)
		return (NULL);
	if (pthread_mutex_init(state_mutex, NULL))
		return (NULL);
	philo->state_mutex = state_mutex;
	philo->nb_eat = 0;
	nb_eat_mutex = ft_malloc(1, sizeof(pthread_mutex_t));
	if (!nb_eat_mutex)
		return (NULL);
	if (pthread_mutex_init(nb_eat_mutex, NULL))
		return (NULL);
	philo->nb_eat_mutex = nb_eat_mutex;
	return (philo);
}

void	set_attr_clock_philo(t_philo *philo, t_clock *clock, t_attr *attr)
{
	philo->attr = attr;
	philo->clock = clock;
}

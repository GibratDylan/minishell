/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:59:44 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 14:29:18 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

pthread_mutex_t	*init_fork(void)
{
	pthread_mutex_t	*fork;

	fork = ft_malloc(1, sizeof(pthread_mutex_t));
	if (!fork)
		return (NULL);
	if (pthread_mutex_init(fork, NULL))
		return (NULL);
	return (fork);
}

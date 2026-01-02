/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:02:29 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:34:10 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

t_philo	*init_philo(int index, sem_t *fork_sem, sem_t *kill_signal,
		t_attr *attr)
{
	t_philo	*philo;

	philo = ft_malloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->fork_sem = fork_sem;
	philo->index = index;
	philo->kill_signal = kill_signal;
	philo->nb_eat = 0;
	philo->attr = attr;
	philo->stop = 0;
	return (philo);
}

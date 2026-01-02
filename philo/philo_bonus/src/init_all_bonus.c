/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:11:34 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 16:34:08 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	init_all_sem(sem_t **fork_sem, sem_t **kill_signal, sem_t **eat_sem,
		sem_t **dead_sem)
{
	sem_unlink(FORK_PATH);
	sem_unlink(KILL_SIGNAL_PATH);
	sem_unlink(EAT_PATH);
	sem_unlink(DEAD_PATH);
	*fork_sem = sem_open(FORK_PATH, O_CREAT, 0777, 0);
	*kill_signal = sem_open(KILL_SIGNAL_PATH, O_CREAT, 0777, 0);
	*eat_sem = sem_open(EAT_PATH, O_CREAT, 0777, 0);
	*dead_sem = sem_open(DEAD_PATH, O_CREAT, 0777, 0);
	return (0);
}

int	create_all_philos(int i, t_attr *attr, t_philo ***all_philo,
		sem_t *print_sem)
{
	sem_t	*fork_sem;
	sem_t	*kill_signal;
	sem_t	*eat_sem;
	sem_t	*dead_sem;
	sem_t	*stop_sem;

	*all_philo = ft_malloc(i, sizeof(t_philo *));
	sem_unlink(STOP_PATH);
	stop_sem = sem_open(STOP_PATH, O_CREAT, 0777, i + 1);
	if (init_all_sem(&fork_sem, &kill_signal, &eat_sem, &dead_sem) || !stop_sem)
		return (1);
	i--;
	while (i >= 0)
	{
		(*all_philo)[i] = init_philo(i, fork_sem, kill_signal, attr);
		if (!((*all_philo)[i]))
			return (1);
		(*all_philo)[i]->is_dead = dead_sem;
		(*all_philo)[i]->is_eat_enough = eat_sem;
		(*all_philo)[i]->stop_sem = stop_sem;
		(*all_philo)[i]->print_sem = print_sem;
		sem_post((*all_philo)[i]->fork_sem);
		i--;
	}
	return (0);
}

int	launch_philo_processes(t_philo **all_philo, int count)
{
	int				pid;
	int				i;
	struct timeval	timestamp;
	int				start_clock;

	i = 0;
	gettimeofday(&timestamp, NULL);
	start_clock = timestamp.tv_sec * 1000 + (timestamp.tv_usec / 1000);
	while (i < count)
	{
		all_philo[i]->start_clock = start_clock;
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			philosopher(all_philo[i]);
			return (1);
		}
		all_philo[i]->pid = pid;
		i++;
	}
	return (0);
}

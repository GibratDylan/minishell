/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:58:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/25 21:26:13 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*take_fork(void *arg)
{
	t_philo			*philo;
	struct timeval	timestamp;

	philo = (t_philo *)arg;
	*(philo->state) = 'W';
	pthread_mutex_lock(philo->left_fork);
	// gettimeofday(&timestamp, NULL);
	// printf("%ld %i has taken a fork\n", timestamp.tv_sec, philo->nb + 1);
	pthread_mutex_lock(philo->right_fork);
	gettimeofday(&timestamp, NULL);
	philo->time_last_eat = timestamp.tv_sec;
	printf("%ld %i is eating\n", timestamp.tv_sec, philo->nb + 1);
	*(philo->state) = 'E';
	usleep(10000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	gettimeofday(&timestamp, NULL);
	printf("%ld %i is thinking\n", timestamp.tv_sec, philo->nb + 1);
	*(philo->state) = 'T';
	return (NULL);
}

void	*philosopher(void *arg)
{
	t_philo			*philo;
	struct timeval	timestamp;
	pthread_t		fork_thread;

	philo = (t_philo *)arg;
	if ((philo->nb + 1) % 2)
		usleep(10000);
	gettimeofday(&timestamp, NULL);
	philo->time_last_eat = timestamp.tv_sec;
	printf("%ld %i is sitting\n", timestamp.tv_sec, philo->nb + 1);
	while (1)
	{
		if (*(philo->state) != 'W' || *(philo->state) != 'E')
		{
			pthread_create(&fork_thread, NULL, take_fork, philo);
			pthread_detach(fork_thread);
			usleep(100);
		}
		gettimeofday(&timestamp, NULL);
		if ((*(philo->state) == 'T' || *(philo->state) == 'W')
			&& (timestamp.tv_sec - philo->time_last_eat) > 10)
			*(philo->state) = 'D';
		usleep(100);
	}
	return (NULL);
}

void	check_state_philo(char *philos_state, int nb_of_philo)
{
	int				i;
	struct timeval	timestamp;

	i = 0;
	while (1)
	{
		if (i > nb_of_philo)
			i = 0;
		if (philos_state[i] == 'D')
		{
			gettimeofday(&timestamp, NULL);
			printf("%ld %i died\n", timestamp.tv_sec, i + 1);
			return ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*prev_fork;
	pthread_mutex_t	*first_fork;
	pthread_t		philo_thread;
	int				i;
	t_philo			*philo;
	char			*philos_state;

	(void)argc;
	prev_fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(prev_fork, NULL);
	first_fork = prev_fork;
	i = ft_atoi(argv[1]);
	philos_state = malloc(sizeof(char) * i);
	memset(philos_state, 'T', i);
	i--;
	while (i)
	{
		right_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(right_fork, NULL);
		philo = malloc(sizeof(t_philo));
		philo->left_fork = prev_fork;
		philo->right_fork = right_fork;
		philo->nb = i;
		philo->state = &philos_state[i];
		pthread_create(&philo_thread, NULL, philosopher, philo);
		pthread_detach(philo_thread);
		prev_fork = right_fork;
		i--;
	}
	philo = malloc(sizeof(t_philo));
	philo->left_fork = prev_fork;
	philo->right_fork = first_fork;
	philo->nb = i;
	philo->state = &philos_state[i];
	pthread_create(&philo_thread, NULL, philosopher, philo);
	pthread_detach(philo_thread);
	check_state_philo(philos_state, ft_atoi(argv[1]) - 1);
	return (0);
}

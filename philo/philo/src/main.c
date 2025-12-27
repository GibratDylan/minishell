/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:58:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/27 01:13:33 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*take_fork(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	*(philo->state) = 'W';
	pthread_mutex_lock(philo->right_fork);
	*(philo->state) = 'F';
	printf("%i %i has taken a fork\n", *(philo->clock), philo->index + 1);
	pthread_mutex_lock(philo->left_fork);
	printf("%i %i has taken a fork\n", *(philo->clock), philo->index + 1);
	*(philo->state) = 'E';
	philo->time_last_eat = *(philo->clock);
	printf("%i %i is eating\n", *(philo->clock), philo->index + 1);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	*(philo->state) = 'S';
	printf("%i %i is sleeping\n", *(philo->clock), philo->index + 1);
	usleep(philo->time_to_sleep);
	*(philo->state) = 'T';
	printf("%i %i is thinking\n", *(philo->clock), philo->index + 1);
	return (NULL);
}

void	*philosopher(void *arg)
{
	t_philo		*philo;
	pthread_t	fork_thread;

	philo = (t_philo *)arg;
	while (*(philo->state) == 'W')
		;
	if ((philo->index + 1) % 2)
		usleep(philo->time_to_eat);
	philo->time_last_eat = *(philo->clock);
	while (1)
	{
		if (*(philo->state) == 'T')
		{
			pthread_create(&fork_thread, NULL, take_fork, philo);
			pthread_detach(fork_thread);
		}
		if (*(philo->clock) - philo->time_last_eat > philo->time_to_die)
		{
			*(philo->state) = 'D';
			return (NULL);
		}
		usleep(50000);
	}
	return (NULL);
}

void	launch_all_philo(char *philos_state, int nb_of_philo)
{
	int	i;

	i = 0;
	while (i < nb_of_philo)
	{
		philos_state[i] = 'T';
		i++;
	}
}

void	check_state_philo(char *philos_state, int nb_of_philo, int *clock)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i > nb_of_philo - 1)
			i = 0;
		if (philos_state[i] == 'D')
		{
			// pthread_mutex_lock(print_mutex);
			printf("%i %i died\n", *clock, i + 1);
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
	int				clock;

	// pthread_mutex_t	*print_mutex;
	(void)argc;
	clock = 0;
	prev_fork = malloc(sizeof(pthread_mutex_t));
	// print_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(prev_fork, NULL);
	// pthread_mutex_init(print_mutex, NULL);
	first_fork = prev_fork;
	i = ft_atoi(argv[1]);
	philos_state = malloc(sizeof(char) * i);
	memset(philos_state, 'W', i);
	i--;
	while (i)
	{
		right_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(right_fork, NULL);
		philo = malloc(sizeof(t_philo));
		philo->left_fork = prev_fork;
		philo->right_fork = right_fork;
		philo->index = i;
		philo->state = &philos_state[i];
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]) * 1000;
		philo->time_to_sleep = ft_atoi(argv[4]) * 1000;
		philo->clock = &clock;
		pthread_create(&philo_thread, NULL, philosopher, philo);
		pthread_detach(philo_thread);
		prev_fork = right_fork;
		i--;
	}
	philo = malloc(sizeof(t_philo));
	philo->left_fork = prev_fork;
	philo->right_fork = first_fork;
	philo->index = i;
	philo->state = &philos_state[i];
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]) * 1000;
	philo->time_to_sleep = ft_atoi(argv[4]) * 1000;
	philo->clock = &clock;
	pthread_create(&philo_thread, NULL, philosopher, philo);
	pthread_detach(philo_thread);
	usleep(100);
	pthread_create(&philo_thread, NULL, ft_clock, &clock);
	pthread_detach(philo_thread);
	launch_all_philo(philos_state, ft_atoi(argv[1]));
	check_state_philo(philos_state, ft_atoi(argv[1]), &clock);
	return (0);
}

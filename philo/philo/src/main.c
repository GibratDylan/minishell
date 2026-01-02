/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:58:39 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 15:37:27 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo		**all_philo;
	t_clock		*clock;
	pthread_t	clock_thread;
	int			number_of_philo;
	t_attr		*attr;

	clock = init_clock();
	if (!clock)
		return (ft_free_all_malloc(), 0);
	attr = ft_malloc(1, sizeof(t_attr));
	if (!attr)
		return (ft_free_all_malloc(), 0);
	number_of_philo = init_attr(attr, argv, argc);
	if (!number_of_philo)
		return (ft_free_all_malloc(), 0);
	all_philo = NULL;
	if (create_all_philos(number_of_philo, attr, clock, &all_philo))
		return (ft_free_all_malloc(), 0);
	if (pthread_create(&clock_thread, NULL, ft_clock, clock))
		return (ft_free_all_malloc(), 0);
	if (launch_philo_threads(all_philo, number_of_philo))
		return (ft_free_all_malloc(), 0);
	check_state_philos(all_philo, number_of_philo);
	terminate_clock(clock, clock_thread);
	return (ft_free_all_malloc(), 0);
}

// test
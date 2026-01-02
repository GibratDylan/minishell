/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:58:39 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 10:14:23 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	close_semaphore(t_philo **all_philo)
{
	sem_close(all_philo[0]->is_eat_enough);
	sem_unlink(EAT_PATH);
	sem_close(all_philo[0]->is_dead);
	sem_unlink(DEAD_PATH);
	sem_close(all_philo[0]->fork_sem);
	sem_unlink(FORK_PATH);
	sem_close(all_philo[0]->kill_signal);
	sem_unlink(KILL_SIGNAL_PATH);
	sem_close(all_philo[0]->stop_sem);
	sem_unlink(STOP_PATH);
	sem_close(all_philo[0]->print_sem);
	sem_unlink(PRINT_PATH);
}

int	main(int argc, char **argv)
{
	t_philo	**all_philo;
	int		number_of_philo;
	t_attr	*attr;

	attr = ft_malloc(1, sizeof(t_attr));
	if (!attr)
		return (ft_free_all_malloc(), 0);
	number_of_philo = init_attr(attr, argv, argc);
	if (!number_of_philo)
		return (ft_free_all_malloc(), 0);
	all_philo = NULL;
	if (create_all_philos(number_of_philo, attr, &all_philo))
		return (close_semaphore(all_philo), ft_free_all_malloc(), 0);
	if (launch_philo_processes(all_philo, number_of_philo))
		return (close_semaphore(all_philo), ft_free_all_malloc(), 0);
	wait_process_end(all_philo, number_of_philo);
	return (close_semaphore(all_philo), ft_free_all_malloc(), 0);
}

// test
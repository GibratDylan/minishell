/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:12:52 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 13:05:23 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philo_dead(t_philo **all_philo, int nb_of_philo, int index)
{
	printf("%i %i died\n", get_clock(all_philo[index]->clock->clock_mutex,
			all_philo[index]->clock->clock_value), all_philo[index]->index + 1);
	close_all_philos(all_philo, nb_of_philo);
}

int	check_eat_philos(t_philo **all_philo, int nb_of_philo)
{
	int	i;

	i = 0;
	while (i < nb_of_philo)
	{
		if (get_nb_eat(all_philo[i]->nb_eat_mutex,
				&(all_philo[i]->nb_eat)) < all_philo[i]->attr->eat_before_end)
			return (0);
		i++;
	}
	if (all_philo[0]->attr->eat_before_end == -1)
		return (0);
	else
		return (1);
}

void	check_state_philos(t_philo **all_philo, int nb_of_philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i > nb_of_philo - 1)
			i = 0;
		if (check_philo_is_dead(all_philo[i]))
		{
			philo_dead(all_philo, nb_of_philo, i);
			return ;
		}
		if (check_eat_philos(all_philo, nb_of_philo))
		{
			close_all_philos(all_philo, nb_of_philo);
			return ;
		}
		i++;
	}
}

int	check_philo_is_dead(t_philo *philo)
{
	if ((get_clock(philo->clock->clock_mutex, philo->clock->clock_value)
			- get_last_time_eat(philo->state_mutex,
				&(philo->time_last_eat)) > philo->attr->time_to_die)
		|| get_state(philo->state_mutex, philo->state) == DEAD)
		return (1);
	return (0);
}

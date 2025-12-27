/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:08:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/27 00:13:07 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *nptr)
{
	unsigned long	i;
	int				sign;
	int				final_nb;

	sign = 1;
	i = 0;
	final_nb = 0;
	if (nptr == NULL)
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		final_nb *= 10;
		final_nb += (nptr[i] - '0');
		i++;
	}
	return (final_nb * sign);
}

// void	*print_state(void *arg)
// {
// 	t_philo			*philo;
// 	struct timeval	timestamp;

// 	philo = (t_philo *)arg;
// 	gettimeofday(&timestamp, NULL);
// 	if (*(philo->state) == 'S')
// 	{
// 		// pthread_mutex_lock(philo->print_mutex);
// 		printf("%ld %i is sleeping\n", timestamp.tv_usec / 1000, philo->index
// 			+ 1);
// 		// pthread_mutex_unlock(philo->print_mutex);
// 	}
// 	else if (*(philo->state) == 'E')
// 	{
// 		philo->time_last_eat = timestamp.tv_usec;
// 		// pthread_mutex_lock(philo->print_mutex);
// 		printf("%ld %i is eating\n", timestamp.tv_usec / 1000, philo->index
// 			+ 1);
// 		// pthread_mutex_unlock(philo->print_mutex);
// 	}
// 	return (NULL);
// }

void	*ft_clock(void *arg)
{
	struct timeval	timestamp;
	int				start;
	int				*clock;

	clock = (int *)arg;
	gettimeofday(&timestamp, NULL);
	start = timestamp.tv_sec * 1000 + (timestamp.tv_usec / 1000);
	while (1)
	{
		gettimeofday(&timestamp, NULL);
		*clock = (timestamp.tv_sec * 1000 + (timestamp.tv_usec / 1000)) - start;
		usleep(1000);
	}
}

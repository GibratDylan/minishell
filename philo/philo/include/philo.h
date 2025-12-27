/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:58:32 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/27 00:45:13 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				index;
	char			*state;
	int				time_last_eat;
	int				time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
	// pthread_mutex_t	*print_mutex;
	int				*clock;
}					t_philo;

int					ft_atoi(const char *nptr);
// void				*print_state(void *arg);
void				*ft_clock(void *clock);

#endif
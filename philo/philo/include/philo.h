/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:58:32 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 19:24:26 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT 'E'
# define SLEEP 'S'
# define THINK 'T'
# define FORK 'F'
# define DEAD 'D'
# define SECOND_TO_MICROSECOND 1000000

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_clock
{
	int				*clock_value;
	pthread_mutex_t	*clock_mutex;
}					t_clock;

typedef struct s_attr
{
	int				time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
	int				eat_before_end;
}					t_attr;

typedef struct s_philo
{
	pthread_t		*thread_philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				index;
	char			*state;
	pthread_mutex_t	*state_mutex;
	int				time_last_eat;
	int				nb_eat;
	pthread_mutex_t	*nb_eat_mutex;
	t_attr			*attr;
	t_clock			*clock;
}					t_philo;

int					ft_atoi(const char *nptr);
void				*ft_clock(void *clock);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_malloc(size_t nmemb, size_t size);
void				ft_free_malloc(void *ptr);
void				ft_free_all_malloc(void);
void				free_node(t_list **malloc_list);
t_list				*new_node(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new_lst);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstlast(t_list *lst);
t_clock				*init_clock(void);
pthread_mutex_t		*init_fork(void);
t_philo				*init_philo(int index, pthread_mutex_t *prev_fork,
						pthread_mutex_t *right_fork, char *state);
int					create_all_philos(int count, t_attr *attr, t_clock *clock,
						t_philo ***all_philo);
int					launch_philo_threads(t_philo **all_philo, int count);
void				take_fork(t_philo *philo);
int					get_last_time_eat(pthread_mutex_t *mutex,
						int *time_last_eat);
int					get_clock(pthread_mutex_t *mutex, int *clock);
char				get_state(pthread_mutex_t *mutex, char *state);
void				modify_state(pthread_mutex_t *mutex, char *state,
						char new_state);
void				modify_time_last_eat(pthread_mutex_t *mutex,
						int *time_last_eat, int new);
void				check_state_philos(t_philo **all_philo, int nb_of_philo);
void				*philosopher(void *arg);
int					lock_first_fork(t_philo *philo);
int					lock_second_fork(t_philo *philo);
int					unlock_first_forks(t_philo *philo);
int					unlock_second_forks(t_philo *philo);
int					action_eat(t_philo *philo);
int					action_sleep(t_philo *philo);
int					action_think(t_philo *philo);
int					check_philo_is_dead(t_philo *philo);
int					init_attr(t_attr *attr, char **argv, int argc);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				close_all_philos(t_philo **all_philo, int nb_of_philo);
void				set_attr_clock_philo(t_philo *philo, t_clock *clock,
						t_attr *attr);
int					get_nb_eat(pthread_mutex_t *mutex, int *nb_eat);
void				add_nb_eat(pthread_mutex_t *mutex, int *nb_eat);
void				modify_clock_value(pthread_mutex_t *mutex, int *clock_value,
						int new);
void				terminate_clock(t_clock *clock, pthread_t clock_thread);

#endif
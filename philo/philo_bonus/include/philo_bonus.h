/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:58:32 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/02 12:57:50 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define SECOND_TO_MICROSECOND 1000000
# define KILL_SIGNAL_PATH "/kill_signal"
# define FORK_PATH "/fork"
# define EAT_PATH "/eat"
# define DEAD_PATH "/dead"
# define STOP_PATH "/stop"
# define PRINT_PATH "/print"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_attr
{
	int				time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
	int				eat_before_end;
}					t_attr;

typedef struct s_philo
{
	pid_t			pid;
	sem_t			*fork_sem;
	sem_t			*kill_signal;
	sem_t			*is_dead;
	sem_t			*is_eat_enough;
	sem_t			*print_sem;
	pthread_t		wait_dead_thread;
	pthread_t		wait_eat_thread;
	int				stop;
	sem_t			*stop_sem;
	int				index;
	int				time_last_eat;
	int				nb_eat;
	int				start_clock;
	t_attr			*attr;
}					t_philo;

typedef struct s_arg
{
	int				nb_of_philo;
	t_philo			*philo;
}					t_arg;

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
t_philo				*init_philo(int index, sem_t *fork_sem, sem_t *kill_signal,
						t_attr *attr);
int					create_all_philos(int count, t_attr *attr,
						t_philo ***all_philo);
int					launch_philo_processes(t_philo **all_philo, int count);
void				philosopher(t_philo *philo);
void				take_fork(t_philo *philo);
int					get_clock(int start);
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
void				wait_process_end(t_philo **philo, int nb_of_philos);
int					check_philo_is_dead(t_philo *philo);
int					check_philo_eat_enough(t_philo *philo);
int					get_stop(t_philo *philo);
void				modify_stop(t_philo *philo, int new);
void				*while_check_philo_is_dead(void *arg);

#endif
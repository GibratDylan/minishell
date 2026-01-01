/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:07:26 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/30 14:08:00 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_eat_before_end(t_attr *attr, char **argv, int argc)
{
	char	*tmp;

	attr->eat_before_end = -1;
	if (argc > 5)
	{
		tmp = ft_itoa(ft_atoi(argv[5]));
		if (ft_strncmp(tmp, argv[5], ft_strlen(argv[5])))
			return (ft_free_malloc(tmp), 1);
		(ft_free_malloc(tmp), attr->eat_before_end = ft_atoi(argv[5]));
	}
	return (0);
}

int	init_attr(t_attr *attr, char **argv, int argc)
{
	char	*tmp;

	if (argc > 6 || argc < 5)
		return (0);
	tmp = ft_itoa(ft_atoi(argv[1]));
	if (ft_strncmp(tmp, argv[1], ft_strlen(argv[1])))
		return (ft_free_malloc(tmp), 0);
	ft_free_malloc(tmp);
	tmp = ft_itoa(ft_atoi(argv[2]));
	if (ft_strncmp(tmp, argv[2], ft_strlen(argv[2])))
		return (ft_free_malloc(tmp), 0);
	(ft_free_malloc(tmp), attr->time_to_die = ft_atoi(argv[2]));
	tmp = ft_itoa(ft_atoi(argv[3]));
	if (ft_strncmp(tmp, argv[3], ft_strlen(argv[3])))
		return (ft_free_malloc(tmp), 0);
	(ft_free_malloc(tmp), attr->time_to_eat = ft_atoi(argv[3]) * 1000);
	tmp = ft_itoa(ft_atoi(argv[4]));
	if (ft_strncmp(tmp, argv[4], ft_strlen(argv[4])))
		return (ft_free_malloc(tmp), 0);
	(ft_free_malloc(tmp), attr->time_to_sleep = ft_atoi(argv[4]) * 1000);
	if (init_eat_before_end(attr, argv, argc))
		return (0);
	return (ft_atoi(argv[1]));
}

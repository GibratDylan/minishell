/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:00:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/28 18:26:10 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0' && i < ULONG_MAX)
		i++;
	return (i);
}

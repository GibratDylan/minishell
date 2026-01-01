/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:15:19 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/31 10:30:36 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		final_nb *= 10;
		final_nb += (nptr[i] - '0');
		i++;
	}
	return (final_nb * sign);
}

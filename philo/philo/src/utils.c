/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:08:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/25 15:10:11 by dgibrat          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:39:23 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 17:42:54 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static t_bool	add_in_final_nb(double *final_nb, const char *nptr, int i)
{
	int	exposent;

	exposent = 0;
	while ((nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
		|| nptr[i] == '.')
	{
		if (nptr[i] == '.' && exposent == 0)
			exposent = ft_strlen(&nptr[i]) - 1;
		else if (nptr[i] == '.' && exposent != 0)
			return (FAIL);
		else
		{
			*final_nb *= 10;
			*final_nb += (nptr[i] - '0');
		}
		i++;
	}
	while (exposent)
	{
		*final_nb /= 10;
		exposent--;
	}
	return (SUCCESS);
}

double	ft_atof(const char *nptr)
{
	unsigned int	i;
	int				sign;
	double			final_nb;

	sign = 1;
	final_nb = 0;
	i = 0;
	if (nptr == NULL)
		return (0);
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (add_in_final_nb(&final_nb, nptr, i))
		return (0);
	return (final_nb * sign);
}

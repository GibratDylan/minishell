/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:12:57 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/19 11:12:39 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_bool	ft_isnumber(const char *str)
{
	int		i;
	t_bool	exposent;

	i = 0;
	exposent = 0;
	if (!str || !ft_strlen(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] == '.' && exposent) || ((str[i] < '0' || str[i] > '9')
				&& str[i] != '.'))
			return (0);
		if (str[i] == '.')
			exposent = 1;
		i++;
	}
	return (1);
}

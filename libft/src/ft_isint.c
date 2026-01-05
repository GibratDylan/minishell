/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:36:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:35:46 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_bool	ft_isint(char *str)
{
	char	*result;

	if (!str)
		return (0);
	result = ft_itoa(ft_atoi(str));
	if (ft_isnumber(str) && !ft_strncmp(str, result, ft_strlen(str)))
		return (ft_free_malloc(result), 1);
	else
		return (ft_free_malloc(result), 0);
}

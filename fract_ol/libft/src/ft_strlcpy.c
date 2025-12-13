/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:39:57 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:34:27 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	unsigned long	i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0' && i + 1 < siz)
	{
		dst[i] = src[i];
		i++;
	}
	if (siz != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

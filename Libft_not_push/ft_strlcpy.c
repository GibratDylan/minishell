/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:39:57 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/07 16:02:38 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	unsigned long	j;

	if (dst == NULL || src == NULL)
		return (0);
	j = 0;
	while (src[j] != '\0' && j + 1 < siz)
	{
		dst[j] = src[j];
		j++;
	}
	if (siz != 0)
		dst[j] = '\0';
	return (ft_strlen(src));
}

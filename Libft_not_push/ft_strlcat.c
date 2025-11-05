/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:58:17 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/04 17:00:02 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	unsigned int	strlen_dst;
	unsigned int	strlen_src;
	unsigned int	i;

	strlen_dst = ft_strlen(dst);
	strlen_src = ft_strlen(src);
	if (strlen_dst >= siz)
	{
		return (siz + strlen_src);
	}
	i = 0;
	while (src[i] != '\0' && ((i + 1) < (siz - strlen_dst)))
	{	
		dst[strlen_dst + i] = src[i];
		i++;
	}
	if (siz > 0)
	{
		dst[strlen_dst + i] = '\0';
	}
	return (strlen_dst + strlen_src);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:43:18 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/05 12:33:58 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int				len_big;
	int				len_little;
	unsigned long	i;

	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	i = 0;
	if (len_big == 0 && len_little == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		if (ft_strncmp(little, &big[i], len_little) == 0)
		{
			return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}

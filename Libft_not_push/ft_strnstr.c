/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:43:18 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 15:44:36 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long	i;
	size_t			len_big;
	size_t			len_little;

	if (big == NULL || little == NULL)
		return (NULL);
	len_big = ft_strlen(big);
	len_little = ft_strlen(little);
	if (len_big == 0 && len_little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len - len_little)
	{
		if (ft_strncmp(little, &big[i], len_little) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

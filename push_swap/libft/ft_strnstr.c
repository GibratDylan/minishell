/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:43:18 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/04 13:38:46 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long	i;
	size_t			len_little;

	len_little = ft_strlen(little);
	if (len_little == 0)
		return (0);
	if (big == NULL || len == 0 || len < len_little)
		return (0);
	i = 0;
	while (big[i] && i < len - len_little + 1)
	{
		if (ft_strncmp(little, &big[i], len_little) == 0)
			return (i);
		i++;
	}
	return (0);
}

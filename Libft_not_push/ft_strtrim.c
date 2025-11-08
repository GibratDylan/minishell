/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:32:40 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 14:48:39 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	end;
	unsigned long	start;
	size_t			len_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) && ft_strchr(set, s1[i + 1]) && i <= len_s1)
		i++;
	start = i + 1;
	i = 0;
	while (ft_strchr(set, s1[i]) && ft_strchr(set, s1[len_s1 - i - 1])
		&& i >= 0)
		i++;
	end = i;
	return (ft_substr(s1, start, end - start));
}

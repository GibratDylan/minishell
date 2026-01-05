/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:12:35 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/20 17:04:39 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim_free(char *s1, char const *set)
{
	unsigned long	i;
	unsigned long	start;
	size_t			len_s1;
	char			*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	while (i < len_s1 && ft_strchr(set, 0, s1[i]))
		i++;
	start = i;
	i = 0;
	while (i < len_s1 && ft_strchr(set, 0, s1[len_s1 - i - 1]))
		i++;
	result = ft_substr(s1, start, len_s1 - i - start);
	ft_free_malloc(s1);
	return (result);
}

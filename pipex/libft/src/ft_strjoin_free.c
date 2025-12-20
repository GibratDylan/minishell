/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:46:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/20 13:47:36 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin_free(char *s1, char const *s2, unsigned int len)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = len;
	len_s2 = ft_strlen(s2);
	if (s2 == NULL || len_s1 + len_s2 + 1 > ULONG_MAX / sizeof(char))
		return (NULL);
	if (!(len_s1 + len_s2))
		return (NULL);
	result = ft_malloc(len_s1 + len_s2 + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcpy(&result[len_s1], s2, len_s2 + 1);
	ft_free_malloc(s1);
	return (result);
}

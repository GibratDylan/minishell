/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:38:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/10 19:29:22 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL || len_s1 + len_s2 + 1 > ULONG_MAX
		/ sizeof(char))
		return (NULL);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcpy(&result[len_s1], s2, len_s2 + 1);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:36:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 12:18:32 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (len + 1 > ULONG_MAX / sizeof(char))
		return (NULL);
	subs = malloc(sizeof(char) * (len + 1));
	if (ft_strlen(s) < start || s == NULL || subs == NULL)
		return (NULL);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}

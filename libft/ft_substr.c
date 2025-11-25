/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:36:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/10 19:03:07 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*subs;

	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}

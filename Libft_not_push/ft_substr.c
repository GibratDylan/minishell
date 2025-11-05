/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:36:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/05 16:36:46 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	subs = malloc(sizeof(char) * (len + 1));
	if (ft_strlen(s) < start || s == NULL || subs == NULL)
		return (NULL);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}

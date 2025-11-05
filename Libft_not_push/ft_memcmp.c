/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:17 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/05 12:19:49 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned int	len_s1;
	unsigned int	len_s2;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	uc_s1 = (unsigned char *) s1;
	uc_s2 = (unsigned char *) s2;
	if ((len_s1 == 0 && len_s2 == 0) || n == 0)
	{
		return (0);
	}
	i = 0;
	while (uc_s1[i] == uc_s2[i] && uc_s1[i] != '\0' && uc_s2[i] != '\0'
		&& (size_t) i < n)
	{
		i++;
	}
	if (i == n)
		return (0);
	return (uc_s1[i] - uc_s2[i]);
}

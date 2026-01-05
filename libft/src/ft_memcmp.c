/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:17 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:35:02 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL || n == 0)
		return (0);
	i = 0;
	while (i < n && uc_s1[i] == uc_s2[i])
		i++;
	if (i == n)
		return (0);
	return (uc_s1[i] - uc_s2[i]);
}

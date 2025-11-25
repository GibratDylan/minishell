/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:54:58 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/13 09:12:30 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_n(long long n)
{
	unsigned long	len_n;

	len_n = 0;
	if (n <= 0)
	{
		len_n++;
		n *= -1;
	}
	while (n > 0)
	{
		len_n++;
		n /= 10;
	}
	return (len_n);
}

char	*ft_itoa(int n)
{
	size_t	len_n;
	char	*result;
	long	l_c;

	l_c = (long long)n;
	len_n = ft_len_n(l_c);
	result = malloc((len_n + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (l_c < 0)
	{
		result[0] = '-';
		l_c *= -1;
	}
	result[len_n--] = '\0';
	while (l_c > 9)
	{
		result[len_n--] = l_c % 10 + '0';
		l_c /= 10;
	}
	result[len_n] = l_c % 10 + '0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:54:58 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/07 17:56:31 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_n(int n)
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

	len_n = ft_len_n(n);
	result = malloc((len_n + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	result[len_n--] = '\0';
	while (n > 9)
	{
		result[len_n--] = n % 10 + '0';
		n /= 10;
	}
	result[len_n] = n % 10 + '0';
	return (result);
}

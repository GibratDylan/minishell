/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:09:18 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:35:42 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_len_n(unsigned long long n, unsigned long len_base)
{
	unsigned long	len_n;

	len_n = 0;
	while (n >= len_base)
	{
		len_n++;
		n /= len_base;
	}
	return (++len_n);
}

char	*ft_itoa_base(unsigned long long n, char *base, t_bool is_address)
{
	size_t	len_n;
	size_t	len_base;
	char	*result;

	if (is_address && n == 0)
		return (ft_strdup("(nil)"));
	len_base = ft_strlen(base);
	len_n = ft_len_n(n, len_base);
	if (is_address)
		len_n += 2;
	result = ft_malloc((len_n + 1), sizeof(char));
	if (result == NULL || base == NULL)
		return (NULL);
	if (is_address)
		ft_strlcpy(result, "0x", 3);
	result[len_n--] = '\0';
	while (n >= len_base)
	{
		result[len_n--] = base[n % len_base];
		n /= len_base;
	}
	result[len_n] = base[n % len_base];
	return (result);
}

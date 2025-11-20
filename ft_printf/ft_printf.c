/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:41:22 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/20 10:40:55 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list list, char *conversion)
{
	char	*tmp;
	int		count;

	if (conversion[0] == '\0')
		return (-1);
	if (conversion[0] == 'c')
	{
		ft_putchar_fd(va_arg(list, int), 1);
		return (1);
	}
	else if (conversion[0] == 'u')
		tmp = ft_itoa_base(va_arg(list, unsigned int), "0123456789", 0);
	else if (conversion[0] == 's')
		tmp = ft_strdup_null(va_arg(list, char *));
	else if (conversion[0] == 'x')
		tmp = ft_itoa_base(va_arg(list, unsigned int), "0123456789abcdef", 0);
	else if (conversion[0] == 'X')
		tmp = ft_itoa_base(va_arg(list, unsigned int), "0123456789ABCDEF", 0);
	else if (conversion[0] == 'p')
		tmp = ft_itoa_base(va_arg(list, unsigned long), "0123456789abcdef", 1);
	else
		tmp = ft_itoa((va_arg(list, int)));
	count = ft_strlen(tmp);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	tmp = NULL;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	unsigned long	i;
	va_list			list;
	char			all_conversions[9];
	int				count;
	int				result_conversion;

	count = 0;
	va_start(list, str);
	ft_strlcpy(all_conversions, "cspdiuxX", 9);
	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%' || ((str[i + 1] == '%' || ft_strchr(all_conversions,
						str[i + 1]) == NULL) && str[i] == '%'))
		{
			ft_putchar_fd(str[i], 1);
			count++;
			if (str[i + 1] == '%' && str[i] == '%')
				i++;
		}
		else
		{
			result_conversion = ft_conversion(list, ft_strchr(all_conversions,
						str[++i]));
			if (result_conversion == -1)
				return (-1);
			count += result_conversion;
		}
		i++;
	}
	va_end(list);
	return (count);
}

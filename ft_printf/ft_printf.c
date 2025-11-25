/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:41:22 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/21 18:00:15 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_and_write(char *tmp)
{
	int	count;

	count = ft_strlen(tmp);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	tmp = NULL;
	return (count);
}

static int	ft_conversion(va_list list, char *conversion)
{
	char	*tmp;

	tmp = NULL;
	if (conversion[0] == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (conversion[0] == '%')
		return (ft_putchar_fd('%', 1));
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
	else if (conversion[0] == 'i' || conversion[0] == 'd')
		tmp = ft_itoa((va_arg(list, int)));
	if (tmp == NULL || conversion[0] == '\0')
		return (-1);
	return (ft_count_and_write(tmp));
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	char	all_cv[10];
	int		count;
	int		result;

	count = 0;
	va_start(list, str);
	ft_strlcpy(all_cv, "cspdiuxX%", 10);
	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		if (*str != '%' || (!(ft_strchr(all_cv, *(str + 1))) && *str == '%'))
			count += ft_putchar_fd(*str, 1);
		else
		{
			result = ft_conversion(list, ft_strchr(all_cv, *(++str)));
			if (result == -1)
				return (-1);
			count += result;
		}
		str++;
	}
	va_end(list);
	return (count);
}

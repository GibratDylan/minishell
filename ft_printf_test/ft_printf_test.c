/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:12:55 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/20 17:08:48 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	result;

	result = ft_printf(" %r ", 'q');
	printf("\n%i\n", result);
	ft_printf("===============================\n");
	result = printf(" %r ", 'q');
	printf("\n%i\n", result);
	return (0);
}

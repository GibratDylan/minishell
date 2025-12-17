/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_circular.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:32:57 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/16 15:22:38 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_bool	init_circular(t_stack *stack, int size)
{
	if (!stack || !size)
		return (FAIL);
	stack->stack = ft_malloc(size, sizeof(int));
	if (!stack->stack)
		return (FAIL);
	stack->top = 0;
	stack->size = 0;
	stack->cap = size;
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:50:55 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 12:12:02 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	move_to_index_a(t_stack *stack, int index, char **result)
{
	int	i;

	i = 0;
	if (index < stack->size_a / 2)
	{
		while (i < index)
		{
			if (rotate_a(stack, result))
				return (FAIL);
			i++;
		}
	}
	else
	{
		while (i < stack->size_a - index)
		{
			if (reverse_rotate_a(stack, result))
				return (FAIL);
			i++;
		}
	}
	return (SUCCESS);
}

t_bool	move_to_index_b(t_stack *stack, int index, char **result)
{
	int	i;

	i = 0;
	if (index < stack->size_b / 2)
	{
		while (i < index)
		{
			if (rotate_b(stack, result))
				return (FAIL);
			i++;
		}
	}
	else
	{
		while (i < stack->size_b - index)
		{
			if (reverse_rotate_b(stack, result))
				return (FAIL);
			i++;
		}
	}
	return (SUCCESS);
}

int	count_move(t_stack *stack, int index)
{
	int	size;
	int	move;

	size = stack->size_b;
	if (index < size / 2)
	{
		if (index_to_go(stack, stack->stack_b[index]) < stack->size_a / 2)
			move = index_to_go(stack, stack->stack_b[index]) + index;
		else
			move = stack->size_a - index_to_go(stack, stack->stack_b[index])
				+ index;
	}
	else
	{
		if (index_to_go(stack, stack->stack_b[index]) < stack->size_a / 2)
			move = index_to_go(stack, stack->stack_b[index]) + (size - index);
		else
			move = stack->size_a - index_to_go(stack, stack->stack_b[index])
				+ (size - index);
	}
	return (move);
}

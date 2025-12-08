/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:46:20 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/08 19:21:36 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_a(t_stack *stack)
{
	int	i;
	int	lowest;
	int	index;

	index = 0;
	lowest = INT_MAX;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < lowest)
		{
			lowest = stack->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	index_to_go(t_stack *stack, int nbr)
{
	int	next_nbr;
	int	size;
	int	i;

	size = stack->size_a;
	i = 0;
	if (nbr < stack->stack_a[lowest_a(stack)])
		return (lowest_a(stack));
	while (i < size)
	{
		if (i == size)
		{
			next_nbr = stack->stack_a[0];
		}
		else
			next_nbr = stack->stack_a[i + 1];
		if (nbr > stack->stack_a[i] && nbr < next_nbr)
			return (i + 1);
		i++;
	}
	return (INT_MAX);
}

t_bool	move_index(t_stack *stack, int index, char **result)
{
	int	index_a;
	int	i;

	index_a = index_to_go(stack, stack->stack_b[index]);
	i = 0;
	if (index_a < stack->size_a / 2)
	{
		while (i < index_a)
		{
			if (rotate_a(stack, result))
				return (FAIL);
			i++;
		}
	}
	else
	{
		while (i < stack->size_a - index_a)
		{
			if (reverse_rotate_a(stack, result))
				return (FAIL);
			i++;
		}
	}
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
	if (push_a(stack, result))
		return (FAIL);
	return (SUCCESS);
}

t_bool	turkish_sort(t_stack *stack, char **result)
{
	int	lowest_move;
	int	index;
	int	size;
	int	i;
	int	move;

	while (stack->size_b > 0)
	{
		size = stack->size_b;
		i = 0;
		index = 0;
		lowest_move = INT_MAX;
		while (i < size)
		{
			if (i < size / 2)
			{
				if (index_to_go(stack, stack->stack_b[i]) < stack->size_a / 2)
					move = index_to_go(stack, stack->stack_b[i]) + i;
				else
					move = stack->size_a - index_to_go(stack, stack->stack_b[i])
						+ i;
			}
			else
			{
				if (index_to_go(stack, stack->stack_b[i]) < stack->size_a / 2)
					move = index_to_go(stack, stack->stack_b[i]) + (size - i);
				else
					move = stack->size_a - index_to_go(stack, stack->stack_b[i])
						+ (size - i);
			}
			if (move <= lowest_move)
			{
				lowest_move = move;
				index = i;
			}
			i++;
		}
		if (move_index(stack, index, result))
			return (FAIL);
	}
	return (SUCCESS);
}

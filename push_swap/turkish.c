/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:46:20 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 12:12:08 by dgibrat          ###   ########.fr       */
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

	index_a = index_to_go(stack, stack->stack_b[index]);
	if (move_to_index_a(stack, index_a, result))
		return (FAIL);
	if (move_to_index_b(stack, index, result))
		return (FAIL);
	if (push_a(stack, result))
		return (FAIL);
	return (SUCCESS);
}

t_bool	turkish_sort(t_stack *stack, char **result)
{
	int	index_lowest_move;
	int	index;
	int	lowest_move;
	int	move;

	while (stack->size_b > 0)
	{
		index = 0;
		index_lowest_move = 0;
		lowest_move = INT_MAX;
		while (index < stack->size_b)
		{
			move = count_move(stack, index);
			if (move <= lowest_move)
			{
				lowest_move = move;
				index_lowest_move = index;
			}
			index++;
		}
		if (move_index(stack, index_lowest_move, result))
			return (FAIL);
	}
	return (SUCCESS);
}

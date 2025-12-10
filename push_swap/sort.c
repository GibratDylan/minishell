/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:42:14 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 11:58:21 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	sort_algo(t_stack *stack, t_chunk *chunk, char **result)
{
	if (stack->size_a == 3)
	{
		if (sort_three_a(stack, result))
			return (FAIL);
		return (SUCCESS);
	}
	else if (stack->size_a == 2)
	{
		if (sort_two_a(stack, result))
			return (FAIL);
		return (SUCCESS);
	}
	if (is_not_sorted(stack))
	{
		if (recursive_chunk(chunk, stack, result))
			return (FAIL);
		if (sort_three_a(stack, result) || turkish_sort(stack, result)
			|| rotate_stack_a(stack, result))
			return (FAIL);
	}
	return (SUCCESS);
}

t_bool	rotate_stack_a(t_stack *stack, char **result)
{
	int	index;
	int	i;

	index = lowest_a(stack);
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

t_bool	sort_two_a(t_stack *stack, char **result)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		if (swap_a(stack, result))
			return (FAIL);
	return (SUCCESS);
}

t_bool	sort_three_a(t_stack *stack, char **result)
{
	int	a;
	int	b;
	int	c;

	a = stack->stack_a[0];
	b = stack->stack_a[1];
	c = stack->stack_a[2];
	if (a > b && b < c && a < c)
		return (swap_a(stack, result));
	else if (a > b && b > c)
		return (swap_a(stack, result) || reverse_rotate_a(stack, result));
	else if (a > b && b < c && a > c)
		return (rotate_a(stack, result));
	else if (a < b && b > c && a < c)
		return (swap_a(stack, result) || rotate_a(stack, result));
	else if (a < b && b > c && a > c)
		return (reverse_rotate_a(stack, result));
	return (SUCCESS);
}

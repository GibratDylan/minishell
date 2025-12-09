/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:01:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 19:10:13 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_b(t_all_stack *stack)
{
	int	tmp;
	int	idx1;
	int	idx2;

	if (stack->stack_b->size < 2)
		return ;
	idx1 = stack->stack_b->top;
	idx2 = (stack->stack_b->top + 1) % stack->stack_b->size;
	tmp = stack->stack_b->stack[idx1];
	stack->stack_b->stack[idx1] = stack->stack_b->stack[idx2];
	stack->stack_b->stack[idx2] = tmp;
}

void	push_b(t_all_stack *stack)
{
	int		i;
	int		new_size;
	int		current_idx;
	t_stack	*stack_b;

	stack_b = stack->stack_b;
	if (stack->stack_a->size == 0)
		return ;
	new_size = stack_b->size + 1;
	i = stack_b->size - 1;
	while (i >= 0)
	{
		current_idx = (stack_b->top + i + 1) % new_size;
		stack_b->stack[current_idx] = stack_b->stack[(stack_b->top + i)
			% stack_b->size];
		i--;
	}
	stack_b->top = (stack_b->top - 1 + new_size) % new_size;
	stack_b->stack[stack_b->top] = stack->stack_a->stack[stack->stack_a->top];
	stack->stack_a->top = (stack->stack_a->top + 1) % stack->stack_a->size;
	stack->stack_a->size--;
	stack_b->size = new_size;
}

void	rotate_b(t_all_stack *stack)
{
	if (stack->stack_b->size == 0)
		return ;
	stack->stack_b->top = (stack->stack_b->top + 1) % stack->stack_b->size;
}

void	reverse_rotate_b(t_all_stack *stack)
{
	if (stack->stack_b->size == 0)
		return ;
	stack->stack_b->top = (stack->stack_b->top - 1 + stack->stack_b->size)
		% stack->stack_b->size;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:01:10 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 19:08:45 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a(t_all_stack *stack)
{
	int	tmp;
	int	idx1;
	int	idx2;

	if (stack->stack_a->size < 2)
		return ;
	idx1 = stack->stack_a->top;
	idx2 = (stack->stack_a->top + 1) % stack->stack_a->size;
	tmp = stack->stack_a->stack[idx1];
	stack->stack_a->stack[idx1] = stack->stack_a->stack[idx2];
	stack->stack_a->stack[idx2] = tmp;
}

void	push_a(t_all_stack *stack)
{
	int		i;
	int		new_size;
	int		current_idx;
	t_stack	*stack_a;

	stack_a = stack->stack_a;
	if (stack->stack_b->size == 0)
		return ;
	new_size = stack_a->size + 1;
	i = stack_a->size - 1;
	while (i >= 0)
	{
		current_idx = (stack_a->top + i + 1) % new_size;
		stack_a->stack[current_idx] = stack_a->stack[(stack_a->top + i)
			% new_size];
		i--;
	}
	stack_a->top = (stack_a->top - 1 + stack_a->size) % stack_a->size;
	stack_a->stack[stack_a->top] = stack->stack_b->stack[stack->stack_b->top];
	stack->stack_b->top = (stack->stack_b->top + 1) % stack->stack_b->size;
	stack->stack_b->size--;
	stack_a->size = new_size;
}

void	rotate_a(t_all_stack *stack)
{
	if (stack->stack_a->size == 0)
		return ;
	stack->stack_a->top = (stack->stack_a->top + 1) % stack->stack_a->size;
}

void	reverse_rotate_a(t_all_stack *stack)
{
	if (stack->stack_a->size == 0)
		return ;
	stack->stack_a->top = (stack->stack_a->top - 1 + stack->stack_a->size)
		% stack->stack_a->size;
}

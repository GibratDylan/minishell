/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:01:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 12:00:29 by dgibrat          ###   ########.fr       */
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
	idx2 = next_circular(stack->stack_b, 1, stack->stack_b->cap);
	tmp = stack->stack_b->stack[idx1];
	stack->stack_b->stack[idx1] = stack->stack_b->stack[idx2];
	stack->stack_b->stack[idx2] = tmp;
}

void	push_b(t_all_stack *stack)
{
	t_stack	*stack_b;

	stack_b = stack->stack_b;
	if (stack->stack_a->size == 0)
		return ;
	stack_b->top = prev_circular(stack_b, 1, stack_b->cap);
	stack_b->stack[stack_b->top] = stack->stack_a->stack[stack->stack_a->top];
	stack->stack_a->top = next_circular(stack->stack_a, 1, stack->stack_a->cap);
	stack->stack_a->size--;
	stack_b->size++;
}

void	rotate_b(t_all_stack *stack)
{
	if (stack->stack_b->size < 2)
		return ;
	stack->stack_b->stack[next_circular(stack->stack_b, stack->stack_b->size,
			stack->stack_b->cap)] = stack->stack_b->stack[stack->stack_b->top];
	stack->stack_b->top = next_circular(stack->stack_b, 1, stack->stack_b->cap);
}

void	reverse_rotate_b(t_all_stack *stack)
{
	t_stack	*stack_b;

	stack_b = stack->stack_b;
	if (stack_b->size < 2)
		return ;
	stack_b->stack[prev_circular(stack_b, 1,
			stack_b->cap)] = stack_b->stack[next_circular(stack_b, stack_b->size
			- 1, stack_b->cap)];
	stack_b->top = prev_circular(stack_b, 1, stack_b->cap);
}

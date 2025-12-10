/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:01:10 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 12:00:09 by dgibrat          ###   ########.fr       */
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
	idx2 = next_circular(stack->stack_a, 1, stack->stack_a->cap);
	tmp = stack->stack_a->stack[idx1];
	stack->stack_a->stack[idx1] = stack->stack_a->stack[idx2];
	stack->stack_a->stack[idx2] = tmp;
}

void	push_a(t_all_stack *stack)
{
	t_stack	*stack_a;

	stack_a = stack->stack_a;
	if (stack->stack_b->size == 0)
		return ;
	stack_a->top = prev_circular(stack_a, 1, stack_a->cap);
	stack_a->stack[stack_a->top] = stack->stack_b->stack[stack->stack_b->top];
	stack->stack_b->top = next_circular(stack->stack_b, 1, stack->stack_b->cap);
	stack->stack_b->size--;
	stack_a->size++;
}

void	rotate_a(t_all_stack *stack)
{
	if (stack->stack_a->size < 2)
		return ;
	stack->stack_a->stack[next_circular(stack->stack_a, stack->stack_a->size,
			stack->stack_a->cap)] = stack->stack_a->stack[stack->stack_a->top];
	stack->stack_a->top = next_circular(stack->stack_a, 1, stack->stack_a->cap);
}

void	reverse_rotate_a(t_all_stack *stack)
{
	t_stack	*stack_a;

	stack_a = stack->stack_a;
	if (stack_a->size < 2)
		return ;
	stack_a->stack[prev_circular(stack_a, 1,
			stack_a->cap)] = stack_a->stack[next_circular(stack_a, stack_a->size
			- 1, stack_a->cap)];
	stack_a->top = prev_circular(stack_a, 1, stack_a->cap);
}

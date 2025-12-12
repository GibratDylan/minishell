/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:26:28 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/12 14:30:16 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	prev_circular(t_stack *stack, int nbr, int cap)
{
	return ((stack->top - nbr + cap) % cap);
}

int	next_circular(t_stack *stack, int nbr, int cap)
{
	return ((stack->top + nbr) % cap);
}

t_bool	sort_with_operation_2(t_all_stack *stack, char *operation)
{
	if (!ft_strncmp(operation, "rb\n", ft_strlen(operation)))
		rotate_b(stack);
	else if (!ft_strncmp(operation, "rr\n", ft_strlen(operation)))
		rotate(stack);
	else if (!ft_strncmp(operation, "rra\n", ft_strlen(operation)))
		reverse_rotate_a(stack);
	else if (!ft_strncmp(operation, "rrb\n", ft_strlen(operation)))
		reverse_rotate_b(stack);
	else if (!ft_strncmp(operation, "rrr\n", ft_strlen(operation)))
		reverse_rotate(stack);
	else
		return (FAIL);
	return (SUCCESS);
}

t_bool	sort_with_operation(t_all_stack *stack, char **operation)
{
	int	i;

	i = 0;
	while (operation[i])
	{
		if (!ft_strncmp(operation[i], "pa\n", ft_strlen(operation[i])))
			push_a(stack);
		else if (!ft_strncmp(operation[i], "pb\n", ft_strlen(operation[i])))
			push_b(stack);
		else if (!ft_strncmp(operation[i], "sa\n", ft_strlen(operation[i])))
			swap_a(stack);
		else if (!ft_strncmp(operation[i], "sb\n", ft_strlen(operation[i])))
			swap_b(stack);
		else if (!ft_strncmp(operation[i], "ss\n", ft_strlen(operation[i])))
			swap(stack);
		else if (!ft_strncmp(operation[i], "ra\n", ft_strlen(operation[i])))
			rotate_a(stack);
		else if (sort_with_operation_2(stack, operation[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

t_bool	is_not_sorted(t_all_stack *stack)
{
	int	i;
	int	idx1;
	int	idx2;

	i = 0;
	while (i < stack->stack_a->size - 1)
	{
		idx1 = next_circular(stack->stack_a, i, stack->stack_a->cap);
		idx2 = next_circular(stack->stack_a, i + 1, stack->stack_a->cap);
		if (stack->stack_a->stack[idx1] > stack->stack_a->stack[idx2])
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

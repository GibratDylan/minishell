/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:26:28 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 19:12:02 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_with_operation(t_all_stack *stack, char **operation)
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
		else if (!ft_strncmp(operation[i], "rb\n", ft_strlen(operation[i])))
			rotate_b(stack);
		else if (!ft_strncmp(operation[i], "rr\n", ft_strlen(operation[i])))
			rotate(stack);
		else if (!ft_strncmp(operation[i], "rra\n", ft_strlen(operation[i])))
			reverse_rotate_a(stack);
		else if (!ft_strncmp(operation[i], "rrb\n", ft_strlen(operation[i])))
			reverse_rotate_b(stack);
		else if (!ft_strncmp(operation[i], "rrr\n", ft_strlen(operation[i])))
			reverse_rotate(stack);
		i++;
	}
}

t_bool	is_not_sorted(t_all_stack *stack)
{
	size_t	i;
	int		idx1;
	int		idx2;
	int		idx3;

	i = 0;
	while (i < stack->stack_a->size - 1)
	{
		idx1 = (stack->stack_a->top + i) % stack->stack_a->cap;
		idx2 = (stack->stack_a->top + 1 + i) % stack->stack_a->cap;
		idx3 = (stack->stack_a->top + 2 + i) % stack->stack_a->cap;
		ft_printf("%i, %i, %i, %i\n", stack->stack_a->stack[idx1],
			stack->stack_a->stack[idx2], stack->stack_a->stack[idx3],
			stack->stack_a->size);
		if (stack->stack_a->stack[idx1] > stack->stack_a->stack[idx2])
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

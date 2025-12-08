/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:10:10 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/08 18:38:50 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	push_b(t_stack *stack, char **result)
{
	int		i;
	char	*str;

	i = stack->size_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i + 1 < stack->size_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->size_b++;
	stack->size_a--;
	str = ft_strjoin(*result, "pb\n");
	if (str == NULL)
		return (FAIL);
	free(*result);
	*result = str;
	return (SUCCESS);
}

t_bool	rotate_b(t_stack *stack, char **result)
{
	int		tmp;
	int		i;
	char	*str;

	tmp = stack->stack_b[0];
	i = 0;
	while (i + 1 < stack->size_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[stack->size_b - 1] = tmp;
	str = ft_strjoin(*result, "rb\n");
	if (str == NULL)
		return (FAIL);
	free(*result);
	*result = str;
	return (SUCCESS);
}

t_bool	reverse_rotate_b(t_stack *stack, char **result)
{
	int		tmp;
	int		i;
	char	*str;

	tmp = stack->stack_b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	str = ft_strjoin(*result, "rrb\n");
	if (str == NULL)
		return (FAIL);
	free(*result);
	*result = str;
	return (SUCCESS);
}

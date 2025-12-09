/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:35:11 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/08 19:11:37 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	swap_a(t_stack *stack, char **result)
{
	int		tmp;
	char	*str;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	str = ft_strjoin(*result, "sa\n");
	if (str == NULL)
		return (FAIL);
	free(*result);
	*result = str;
	return (SUCCESS);
}

t_bool	push_a(t_stack *stack, char **result)
{
	int		i;
	char	*str;

	i = stack->size_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i + 1 < stack->size_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->size_a++;
	stack->size_b--;
	str = ft_strjoin(*result, "pa\n");
	if (str == NULL)
		return (FAIL);
	free(*result);
	*result = str;
	return (SUCCESS);
}

t_bool	rotate_a(t_stack *stack, char **result)
{
	int		tmp;
	int		i;
	char	*str;

	tmp = stack->stack_a[0];
	i = 0;
	while (i + 1 < stack->size_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->size_a - 1] = tmp;
	str = ft_strjoin(*result, "ra\n");
	if (str == NULL)
		return (FAIL);
	free(*result);
	*result = str;
	return (SUCCESS);
}

t_bool	reverse_rotate_a(t_stack *stack, char **result)
{
	int		tmp;
	int		i;
	char	*str;

	tmp = stack->stack_a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	str = ft_strjoin(*result, "rra\n");
	if (str == NULL)
		return (FAIL);
	free(*result);
	*result = str;
	return (SUCCESS);
}

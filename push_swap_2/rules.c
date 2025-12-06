/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:10:10 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/06 18:57:57 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char stack_c, char **result)
{
	int		tmp;
	char	*str;

	if (stack_c == 'a')
	{
		if (stack->size_a < 2)
			return ;
		tmp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = tmp;
	}
	else if (stack_c == 'b')
	{
		if (stack->size_b < 2)
			return ;
		tmp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = tmp;
	}
	if (stack_c == 'a')
		str = ft_strjoin(*result, "sa\n");
	else
		str = ft_strjoin(*result, "sb\n");
	free(*result);
	*result = str;
}

void	push(t_stack *stack, char stack_c, char **result)
{
	int		i;
	char	*str;

	if (stack_c == 'a')
	{
		if (stack->size_b == 0)
			return ;
		/* shift a to right */
		i = stack->size_a;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		/* move top of b to a */
		stack->stack_a[0] = stack->stack_b[0];
		/* shift b to left */
		i = 0;
		while (i + 1 < stack->size_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->size_a++;
		stack->size_b--;
	}
	else if (stack_c == 'b')
	{
		if (stack->size_a == 0)
			return ;
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
	}
	if (stack_c == 'a')
		str = ft_strjoin(*result, "pa\n");
	else
		str = ft_strjoin(*result, "pb\n");
	free(*result);
	*result = str;
}

void	rotate(t_stack *stack, char stack_c, char **result)
{
	int		tmp;
	int		i;
	char	*str;

	if (stack_c == 'a')
	{
		if (stack->size_a < 2)
			return ;
		tmp = stack->stack_a[0];
		i = 0;
		while (i + 1 < stack->size_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->stack_a[stack->size_a - 1] = tmp;
	}
	else if (stack_c == 'b')
	{
		if (stack->size_b < 2)
			return ;
		tmp = stack->stack_b[0];
		i = 0;
		while (i + 1 < stack->size_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[stack->size_b - 1] = tmp;
	}
	if (stack_c == 'a')
		str = ft_strjoin(*result, "ra\n");
	else
		str = ft_strjoin(*result, "rb\n");
	free(*result);
	*result = str;
}

void	reverse_rotate(t_stack *stack, char stack_c, char **result)
{
	int		tmp;
	int		i;
	char	*str;

	if (stack_c == 'a')
	{
		if (stack->size_a < 2)
			return ;
		tmp = stack->stack_a[stack->size_a - 1];
		i = stack->size_a - 1;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = tmp;
	}
	else if (stack_c == 'b')
	{
		if (stack->size_b < 2)
			return ;
		tmp = stack->stack_b[stack->size_b - 1];
		i = stack->size_b - 1;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = tmp;
	}
	if (stack_c == 'a')
		str = ft_strjoin(*result, "rra\n");
	else
		str = ft_strjoin(*result, "rrb\n");
	free(*result);
	*result = str;
}

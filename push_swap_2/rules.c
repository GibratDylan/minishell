/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:10:10 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/02 16:34:37 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char stack_c)
{
	int	tmp;

	if (stack_c == 'a')
	{
		if (stack->size_a < 2)
			return ;
		tmp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = tmp;
		ft_printf("sa\n");
	}
	else if (stack_c == 'b')
	{
		if (stack->size_b < 2)
			return ;
		tmp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = tmp;
		ft_printf("sb\n");
	}
}

void	swap_s(t_stack *stack)
{
	int	tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = tmp;
	}
	if (stack->size_b > 1)
	{
		tmp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = tmp;
	}
	ft_printf("ss\n");
}

void	push(t_stack *stack, char stack_c)
{
	int	i;

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
		ft_printf("pa\n");
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
		ft_printf("pb\n");
	}
}

void	rotate(t_stack *stack, char stack_c)
{
	int	tmp;
	int	i;

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
		ft_printf("ra\n");
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
		ft_printf("rb\n");
	}
}

void	rotate_r(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_a > 1)
	{
		tmp = stack->stack_a[0];
		i = 0;
		while (i + 1 < stack->size_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->stack_a[stack->size_a - 1] = tmp;
	}
	if (stack->size_b > 1)
	{
		tmp = stack->stack_b[0];
		i = 0;
		while (i + 1 < stack->size_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[stack->size_b - 1] = tmp;
	}
	ft_printf("rr\n");
}

void	reverse_rotate(t_stack *stack, char stack_c)
{
	int	tmp;
	int	i;

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
		ft_printf("rra\n");
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
		ft_printf("rrb\n");
	}
}

void	reverse_rotate_r(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b > 1)
	{
		tmp = stack->stack_b[stack->size_b - 1];
		i = stack->size_b - 1;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = tmp;
	}
	if (stack->size_a > 1)
	{
		tmp = stack->stack_a[stack->size_a - 1];
		i = stack->size_a - 1;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = tmp;
	}
	ft_printf("rrr\n");
}

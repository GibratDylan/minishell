/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:10:10 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/01 12:52:09 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char stack_c)
{
	int	tmp;

	tmp = stack->next->content;
	stack->next->content = stack->content;
	stack->content = tmp;
	if (stack_c == 'a')
		ft_printf("sa\n");
	else if (stack_c == 'b')
		ft_printf("sb\n");
}

void	swap_s(t_list *stack_a, t_list *stack_b)
{
	int	tmp;

	tmp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = tmp;
	tmp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = tmp;
	ft_printf("ss\n");
}

void	push(t_list **stack_from, t_list **stack_to, char stack_c)
{
	t_list	*tmp;

	ft_lstadd_front(stack_to, ft_lstnew((*stack_from)->content));
	tmp = (*stack_from)->next;
	ft_lstdelone(*stack_from);
	*stack_from = tmp;
	if (stack_c == 'a')
		ft_printf("pa\n");
	else if (stack_c == 'b')
		ft_printf("pb\n");
}

void	rotate(t_list *stack, char stack_c)
{
	int		fisrt_val;
	int		tmp;
	t_list	*cur;

	fisrt_val = stack->content;
	cur = stack;
	while (cur->next)
	{
		tmp = cur->next->content;
		cur->content = tmp;
		cur = cur->next;
	}
	cur->content = fisrt_val;
	if (stack_c == 'a')
		ft_printf("ra\n");
	else if (stack_c == 'b')
		ft_printf("rb\n");
}

void	rotate_r(t_list *stack_a, t_list *stack_b)
{
	int		fisrt_val;
	int		tmp;
	t_list	*cur;

	fisrt_val = stack_a->content;
	cur = stack_a;
	while (cur->next)
	{
		tmp = cur->next->content;
		cur->content = tmp;
		cur = cur->next;
	}
	cur->content = fisrt_val;
	fisrt_val = stack_b->content;
	cur = stack_b;
	while (cur->next)
	{
		tmp = cur->next->content;
		cur->content = tmp;
		cur = cur->next;
	}
	cur->content = fisrt_val;
	ft_printf("rr\n");
}

void	reverse_rotate(t_list *stack, char stack_c)
{
	int		last_val;
	int		tmp;
	t_list	*cur;

	last_val = ft_lstlast(stack)->content;
	cur = stack;
	while (cur)
	{
		tmp = cur->content;
		cur->content = last_val;
		last_val = tmp;
		cur = cur->next;
	}
	if (stack_c == 'a')
		ft_printf("rra\n");
	else if (stack_c == 'b')
		ft_printf("rrb\n");
}

void	reverse_rotate_r(t_list *stack_a, t_list *stack_b)
{
	int		last_val;
	int		tmp;
	t_list	*cur;

	last_val = ft_lstlast(stack_b)->content;
	cur = stack_b;
	while (cur)
	{
		tmp = cur->content;
		cur->content = last_val;
		last_val = tmp;
		cur = cur->next;
	}
	last_val = ft_lstlast(stack_a)->content;
	cur = stack_a;
	while (cur)
	{
		tmp = cur->content;
		cur->content = last_val;
		last_val = tmp;
		cur = cur->next;
	}
	ft_printf("rrr\n");
}

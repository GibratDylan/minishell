/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:10:10 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/26 18:57:07 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *stack_a)
{
	int	tmp;

	tmp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_list *stack_b)
{
	int	tmp;

	tmp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = tmp;
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

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->content));
	tmp = (*stack_a)->next;
	ft_lstdelone(*stack_a);
	*stack_a = tmp;
	ft_printf("pb\n");
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->content));
	tmp = (*stack_b)->next;
	ft_lstdelone(*stack_b);
	*stack_b = tmp;
	ft_printf("pa\n");
}

void	reverse_rotate_a(t_list *stack_a)
{
	int		last_val;
	int		tmp;
	t_list	*last;
	t_list	*cur;

	if (!stack_a || !stack_a->next)
		return ;
	last = stack_a;
	while (last->next)
		last = last->next;
	last_val = last->content;
	cur = stack_a;
	while (cur)
	{
		tmp = cur->content;
		cur->content = last_val;
		last_val = tmp;
		cur = cur->next;
	}
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list *stack_b)
{
	int		last_val;
	int		tmp;
	t_list	*last;
	t_list	*cur;

	if (!stack_b || !stack_b->next)
		return ;
	last = stack_b;
	while (last->next)
		last = last->next;
	last_val = last->content;
	cur = stack_b;
	while (cur)
	{
		tmp = cur->content;
		cur->content = last_val;
		last_val = tmp;
		cur = cur->next;
	}
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_list *stack_a, t_list *stack_b)
{
	int		last_val;
	int		tmp;
	t_list	*last;
	t_list	*cur;

	if (stack_b && stack_b->next)
	{
		last = stack_b;
		while (last->next)
			last = last->next;
		last_val = last->content;
		cur = stack_b;
		while (cur)
		{
			tmp = cur->content;
			cur->content = last_val;
			last_val = tmp;
			cur = cur->next;
		}
	}
	if (stack_a && stack_a->next)
	{
		last = stack_a;
		while (last->next)
			last = last->next;
		last_val = last->content;
		cur = stack_a;
		while (cur)
		{
			tmp = cur->content;
			cur->content = last_val;
			last_val = tmp;
			cur = cur->next;
		}
	}
	ft_printf("rrr\n");
}

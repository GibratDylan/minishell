/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/27 19:37:52 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	init_statck(t_list **stack_a, int argc, char *argv[])
{
	int		content;
	t_list	*new;
	t_list	*tmp;

	while (argc > 1)
	{
		content = ft_atoi(argv[argc - 1]);
		tmp = *stack_a;
		while (tmp)
		{
			if (content == tmp->content)
				return (ft_lstclear(stack_a), FAIL);
			tmp = tmp->next;
		}
		new = ft_lstnew(content);
		if (!new)
			return (ft_lstclear(stack_a), FAIL);
		ft_lstadd_front(stack_a, new);
		argc--;
	}
	return (SUCCESS);
}

static t_bool	check_argv(int argc, char *argv[])
{
	char	*result;

	while (argc > 1)
	{
		result = ft_itoa(ft_atoi(argv[argc - 1]));
		if (result == NULL)
			return (FAIL);
		if (ft_strncmp(argv[argc - 1], result, ft_strlen(argv[argc - 1])))
			return (free(result), FAIL);
		free(result);
		argc--;
	}
	return (SUCCESS);
}

static t_bool	lstis_sorted(t_list *stack, t_bool is_reversed)
{
	while (stack && stack->next)
	{
		if (!is_reversed && stack->content > stack->next->content)
			return (0);
		else if (is_reversed && stack->content < stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// static t_list	*lstindex(t_list *stack_a, int index)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_a->next && i < index)
// 	{
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// 	return (stack_a);
// }

static void	sort_algo(t_list **stack_a, t_list **stack_b)
{
	while (!lstis_sorted(*stack_a, 0))
	{
		while (*stack_a && !lstis_sorted(*stack_a, 0))
		{
			if (*stack_a && (*stack_a)->next
				&& ft_lstlast(*stack_a)->content < (*stack_a)->content
				&& *stack_b && (*stack_b)->next
				&& ft_lstlast(*stack_b)->content > (*stack_b)->content)
				reverse_rotate_r(*stack_a, *stack_b);
			if (*stack_a && (*stack_a)->next
				&& ft_lstlast(*stack_a)->content < (*stack_a)->content)
				reverse_rotate(*stack_a, 'a');
			if (*stack_a && (*stack_a)->next
				&& (*stack_a)->content > (*stack_a)->next->content && *stack_b
				&& (*stack_b)->next
				&& (*stack_b)->content < (*stack_b)->next->content)
				swap_s(*stack_a, *stack_b);
			if (*stack_a && (*stack_a)->next
				&& (*stack_a)->content > (*stack_a)->next->content)
				swap(*stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
		while (*stack_b)
		{
			if (*stack_a && (*stack_a)->next
				&& ft_lstlast(*stack_a)->content < (*stack_a)->content
				&& *stack_b && (*stack_b)->next
				&& ft_lstlast(*stack_b)->content > (*stack_b)->content)
				reverse_rotate_r(*stack_a, *stack_b);
			if (*stack_b && (*stack_b)->next
				&& ft_lstlast(*stack_b)->content > (*stack_b)->content)
				reverse_rotate(*stack_b, 'b');
			if (*stack_b && (*stack_b)->next
				&& (*stack_b)->content < (*stack_b)->next->content && *stack_a
				&& (*stack_a)->next
				&& (*stack_a)->content > (*stack_a)->next->content)
				swap_s(*stack_a, *stack_b);
			if (*stack_b && (*stack_b)->next
				&& (*stack_b)->content < (*stack_b)->next->content)
				swap(*stack_b, 'b');
			push(stack_b, stack_a, 'a');
		}
	}
}

// static void	lstbiggest_content(t_list *stack)
// {
// 	int	biggest;
// 	int	size_stack;
// 	int	i;

// 	size_stack = ft_lstsize(stack);
// 	biggest = 0;
// 	i = 0;
// 	while (i < size_stack)
// 	{
// 		if (biggest < stack->content)
// 			biggest = stack->content;
// 		stack = stack->next;
// 		i++;
// 	}
// }

// static void	sort_algo(t_list **stack_a, t_list **stack_b)
// {
// 	while (*stack_a)
// 	{
// 		if (*stack_a && (*stack_a)->next
// 			&& ft_lstlast(*stack_a)->content < (*stack_a)->content)
// 			reverse_rotate(*stack_a, 'a');
// 		else if (*stack_a && (*stack_a)->next
// 			&& (*stack_a)->content > (*stack_a)->next->content)
// 			swap(*stack_a, 'a');
// 		else if (!*stack_b || (*stack_a)->content > (*stack_b)->content)
// 			push(stack_a, stack_b, 'b');
// 		else if (*stack_b && (*stack_a)->content < (*stack_b)->content)
// 		{
// 			rotate(*stack_a, 'a');
// 			while (*stack_b
// 				&& ft_lstlast(*stack_a)->content < (*stack_b)->content)
// 				push(stack_b, stack_a, 'a');
// 			reverse_rotate(*stack_a, 'a');
// 			push(stack_a, stack_b, 'b');
// 		}
// 	}
// 	while (*stack_b)
// 	{
// 		push(stack_b, stack_a, 'a');
// 	}
// }

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (SUCCESS);
	if (check_argv(argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	if (init_statck(&stack_a, argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	sort_algo(&stack_a, &stack_b);
	while (stack_a)
	{
		// ft_printf("%i\n", stack_a->content);
		tmp = stack_a->next;
		ft_lstdelone(stack_a);
		stack_a = tmp;
	}
}

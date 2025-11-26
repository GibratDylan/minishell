/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/26 19:50:07 by dgibrat          ###   ########.fr       */
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

static t_list	*lstindex(t_list *stack_a, int index)
{
	int	i;

	i = 0;
	while (stack_a->next && i < index)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (stack_a);
}

static void	sort_algo(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	tmp_index;
	int	i;

	index = 0;
	i = 0;
	while (i < 50)
	{
		push_b(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < 21)
	{
		while (index < ft_lstsize(*stack_a))
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
			{
				swap_a(*stack_a);
				index = 0;
			}
			else if (lstindex((*stack_a), index)->content > lstindex((*stack_a),
					index + 1)->content)
			{
				tmp_index = 0;
				while (tmp_index < index)
				{
					push_b(stack_a, stack_b);
					tmp_index++;
				}
				index = 0;
				swap_a(*stack_a);
			}
			if (*stack_b && (*stack_b)->content < (*stack_b)->next->content)
			{
				swap_b(*stack_b);
				index = 0;
			}
			index++;
		}
		while ((*stack_b))
		{
			if ((*stack_b)->next
				&& (*stack_a)->content > (*stack_a)->next->content
				&& (*stack_b)->content < (*stack_b)->next->content)
				swap_s(*stack_a, *stack_b);
			else if ((*stack_a)->content > (*stack_a)->next->content)
				swap_a(*stack_a);
			push_a(stack_a, stack_b);
		}
		i++;
		index = 0;
	}
}

// static void	sort_algo(t_list **stack_a, t_list **stack_b)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 50)
// 	{
// 		push_b(stack_a, stack_b);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 500000)
// 	{
// 		if (*stack_a && (*stack_a)->next
// 			&& (*stack_a)->content > (*stack_a)->next->content)
// 			swap_a(*stack_a);
// 		if (*stack_b && (*stack_b)->next
// 			&& (*stack_b)->content < (*stack_b)->next->content)
// 			swap_b(*stack_b);
// 		reverse_rotate_r(*stack_a, *stack_b);
// 		i++;
// 	}
// 	while ((*stack_b))
// 		push_a(stack_a, stack_b);
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

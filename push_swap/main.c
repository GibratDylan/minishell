/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/02 10:42:17 by dgibrat          ###   ########.fr       */
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

// static t_bool	lstis_sorted(t_list *stack, t_bool is_reversed)
// {
// 	while (stack && stack->next)
// 	{
// 		if (!is_reversed && stack->content > stack->next->content)
// 			return (0);
// 		else if (is_reversed && stack->content < stack->next->content)
// 			return (0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

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

static int	lstbiggest_content(t_list *stack)
{
	int	biggest;

	biggest = INT_MIN;
	while (stack)
	{
		if (biggest < stack->content)
			biggest = stack->content;
		stack = stack->next;
	}
	return (biggest);
}

// static int	lstlowest_content(t_list *stack)
// {
// 	int	lowest;
// 	int	size_stack;

// 	size_stack = ft_lstsize(stack);
// 	lowest = INT_MAX;
// 	while (stack->next)
// 	{
// 		if (lowest > stack->content)
// 			lowest = stack->content;
// 		stack = stack->next;
// 	}
// 	return (lowest);
// }

// static t_bool	no_more_valide_bits(t_list *stack, int count,
// 		int biggest_content, int bits_to_find)
// {
// 	int	number_bits;
// 	int	i;

// 	while (stack)
// 	{
// 		number_bits = stack->content;
// 		i = 0;
// 		while (biggest_content - i > count)
// 		{
// 			number_bits >>= 1;
// 			i++;
// 		}
// 		if (!bits_to_find && !(number_bits & 1))
// 			return (0);
// 		if (bits_to_find && (number_bits & 1))
// 			return (0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

static void	sort_algo(t_list **stack_a, t_list **stack_b)
{
	int	count;
	int	biggest_content;
	int	i;
	int	size_stack;

	biggest_content = lstbiggest_content(*stack_a);
	count = 0;
	while (biggest_content)
	{
		count++;
		biggest_content >>= 1;
	}
	biggest_content = count;
	while (count > 0)
	{
		i = 0;
		size_stack = ft_lstsize(*stack_a);
		while (*stack_a && i < size_stack)
		{
			if (!(((*stack_a)->content >> (biggest_content - count)) & 1))
				push(stack_a, stack_b, 'b');
			else
				rotate(*stack_a, 'a');
			i++;
		}
		i = 0;
		size_stack = ft_lstsize(*stack_b);
		if (count != biggest_content)
		{
			while (*stack_b && i < size_stack)
			{
				if (((*stack_b)->content >> (biggest_content - count)) & 1)
					push(stack_b, stack_a, 'a');
				else
					rotate(*stack_b, 'b');
				i++;
			}
		}
		count--;
	}
	while (*stack_b)
	{
		push(stack_b, stack_a, 'a');
	}
}

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

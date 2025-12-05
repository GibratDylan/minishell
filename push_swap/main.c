/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/05 14:15:46 by dgibrat          ###   ########.fr       */
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

// static int	lstbiggest_content(t_list *stack)
// {
// 	int	biggest;
// 	int	index;
// 	int	result;

// 	index = 0;
// 	biggest = INT_MIN;
// 	result = 0;
// 	while (stack)
// 	{
// 		if (biggest < stack->content)
// 		{
// 			biggest = stack->content;
// 			result = index;
// 		}
// 		stack = stack->next;
// 		index++;
// 	}
// 	return (result);
// }

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

// static int	lstfound_content(t_list *stack, int content)
// {
// 	int	index;

// 	index = 0;
// 	while (stack)
// 	{
// 		if (content == stack->content)
// 		{
// 			return (index);
// 		}
// 		stack = stack->next;
// 		index++;
// 	}
// 	return (-1);
// }

static int	get_lowest_with_tmp(t_list *stack_a, int *tmp, int size_stack)
{
	int	lowest;
	int	i;

	lowest = INT_MAX;
	i = 0;
	while (stack_a)
	{
		if (stack_a->content < lowest && i < size_stack && tmp[i] == -1)
			lowest = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	return (lowest);
}

static int	get_lowest(t_list *stack)
{
	int	lowest;
	int	index;
	int	result;

	index = 0;
	lowest = INT_MAX;
	result = 0;
	while (stack)
	{
		if (lowest > stack->content)
		{
			lowest = stack->content;
			result = index;
		}
		stack = stack->next;
		index++;
	}
	return (result);
}

static t_bool	compress_value(t_list *stack_a)
{
	int		*tmp;
	int		i;
	int		index;
	int		size_stack;
	t_list	*head;

	size_stack = ft_lstsize(stack_a);
	if (size_stack <= 0)
		return (FAIL);
	tmp = malloc(size_stack * sizeof(int));
	if (tmp == NULL)
		return (FAIL);
	i = 0;
	while (i < size_stack)
		tmp[i++] = -1;
	index = 0;
	i = 0;
	head = stack_a;
	while (head)
	{
		if (head->content == get_lowest_with_tmp(stack_a, tmp, size_stack))
		{
			head->content = index;
			tmp[i] = index;
			index++;
			head = stack_a;
			i = 0;
			continue ;
		}
		head = head->next;
		i++;
	}
	return (free(tmp), tmp = NULL, SUCCESS);
}

static void	sort_algo(t_list **stack_a, t_list **stack_b, char **result)
{
	int	nb_chunk;
	int	i;
	int	size_stack;
	int	size_chunk;
	int	max_chunk;

	nb_chunk = 7;
	size_chunk = ft_lstsize(*stack_a) / nb_chunk;
	max_chunk = size_chunk;
	while (nb_chunk >= 0 && !lstis_sorted(*stack_a, 0))
	{
		i = 0;
		size_stack = ft_lstsize(*stack_a);
		while (*stack_a && i < size_stack)
		{
			if ((*stack_a)->content < max_chunk)
				push(stack_a, stack_b, 'b', result);
			else if ((*stack_a)->content < max_chunk)
			{
				push(stack_a, stack_b, 'b', result);
				rotate(*stack_b, 'b', result);
			}
			else if (get_lowest(*stack_a) > size_stack / 2)
				reverse_rotate(*stack_a, 'a', result);
			else
				rotate(*stack_a, 'a', result);
			i++;
		}
		max_chunk += size_chunk;
		nb_chunk--;
	}
	// while (*stack_b)
	// {
	// 	size_stack = lstbiggest_content(*stack_b);
	// 	size_chunk = ft_lstsize(*stack_b);
	// 	if (size_stack > size_chunk / 2)
	// 	{
	// 		while (size_chunk - size_stack > 0)
	// 		{
	// 			reverse_rotate(*stack_b, 'b', result);
	// 			size_stack++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (size_stack > 0)
	// 		{
	// 			rotate(*stack_b, 'b', result);
	// 			size_stack--;
	// 		}
	// 	}
	// 	push(stack_b, stack_a, 'a', result);
	// }
}

// static void	sort_algo(t_list **stack_a, t_list **stack_b, char **result)
// {
// 	int	count;
// 	int	biggest_content;
// 	int	i;
// 	int	size_stack;

// 	biggest_content = lstbiggest_content(*stack_a);
// 	count = 0;
// 	while (biggest_content)
// 	{
// 		count++;
// 		biggest_content >>= 1;
// 	}
// 	biggest_content = count;
// 	while (count > 0)
// 	{
// 		i = 0;
// 		size_stack = ft_lstsize(*stack_a);
// 		if (!(no_more_valide_bits(*stack_a, count, biggest_content, 0)))
// 		{
// 			while (*stack_a && i < size_stack && !(lstis_sorted(*stack_a, 0)))
// 			{
// 				if (!(((*stack_a)->content >> (biggest_content - count)) & 1))
// 					push(stack_a, stack_b, 'b', result);
// 				else
// 					rotate(*stack_a, 'a', result);
// 				i++;
// 			}
// 		}
// 		i = 0;
// 		size_stack = ft_lstsize(*stack_b);
// 		if (biggest_content - count + 1 < biggest_content
// 			&& !(no_more_valide_bits(*stack_a, count, biggest_content, 1)))
// 		{
// 			while (*stack_b && i < size_stack)
// 			{
// 				if ((*stack_b)->content >> (biggest_content - count + 1) & 1)
// 					push(stack_b, stack_a, 'a', result);
// 				else
// 					rotate(*stack_b, 'b', result);
// 				i++;
// 			}
// 		}
// 		count--;
// 	}
// 	while (*stack_b)
// 	{
// 		push(stack_b, stack_a, 'a', result);
// 	}
// }

static int	check_for_opti_result(char *result)
{
	if (ft_strnstr(result, "pa\npb\n", ft_strlen(result)))
		return (1);
	else if (ft_strnstr(result, "pb\npa\n", ft_strlen(result)))
		return (2);
	else if (ft_strnstr(result, "rb\nra\n", ft_strlen(result)))
		return (3);
	else if (ft_strnstr(result, "ra\nrb\n", ft_strlen(result)))
		return (4);
	else if (ft_strnstr(result, "\nrrb\nrb\n", ft_strlen(result)))
		return (5);
	else if (ft_strnstr(result, "\nrb\nrrb\n", ft_strlen(result)))
		return (6);
	return (SUCCESS);
}

static void	delete_or_remplace(char **result, int operation)
{
	char	*start;
	char	*end;
	int		index;

	if (operation == 1)
	{
		index = ft_strnstr(*result, "pa\npb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index);
		end = ft_substr(*result, index + 6, ft_strlen(*result));
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 2)
	{
		index = ft_strnstr(*result, "pb\npa\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index);
		end = ft_substr(*result, index + 6, ft_strlen(*result));
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 3)
	{
		index = ft_strnstr(*result, "rb\nra\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index);
		end = ft_substr(*result, index + 3, ft_strlen(*result));
		end[1] = 'r';
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 4)
	{
		index = ft_strnstr(*result, "ra\nrb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index);
		end = ft_substr(*result, index + 3, ft_strlen(*result));
		end[1] = 'r';
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 5)
	{
		index = ft_strnstr(*result, "\nrrb\nrb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 8, ft_strlen(*result));
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 6)
	{
		index = ft_strnstr(*result, "\nrb\nrrb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 8, ft_strlen(*result));
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
}

static void	clear_result(char **result)
{
	int	operation;

	operation = check_for_opti_result(*result);
	while (operation)
	{
		delete_or_remplace(result, operation);
		operation = check_for_opti_result(*result);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*result;

	result = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		return (SUCCESS);
	if (check_argv(argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	if (init_statck(&stack_a, argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	compress_value(stack_a);
	sort_algo(&stack_a, &stack_b, &result);
	ft_lstclear(&stack_a);
	clear_result(&result);
	ft_printf("%s", result);
	free(result);
}

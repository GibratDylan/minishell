/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/06 20:33:06 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	malloc_init_stack(int argc, char *argv[], t_stack *stack)
{
	int	content;
	int	i;
	int	j;

	stack->stack_a = malloc((argc - 1) * sizeof(int));
	if (stack->stack_a == NULL)
		return (FAIL);
	stack->stack_b = malloc((argc - 1) * sizeof(int));
	if (stack->stack_b == NULL)
		return (SUCCESS);
	j = 1;
	while (j < argc)
	{
		content = ft_atoi(argv[j]);
		i = 0;
		while (i < stack->size_a)
		{
			if (content == stack->stack_a[i++])
				return (FAIL);
		}
		stack->stack_a[stack->size_a] = content;
		stack->size_a++;
		j++;
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

static int	get_lowest(int *stack_a, int *tmp, t_stack *stack)
{
	int	i;
	int	lowest;

	lowest = INT_MAX;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack_a[i] < lowest && tmp[i] == -1)
			lowest = stack_a[i];
		i++;
	}
	return (lowest);
}

static t_bool	compress_value(t_stack *stack)
{
	int	*tmp;
	int	i;
	int	index;

	if (stack->size_a == 0)
		return (FAIL);
	tmp = malloc(stack->size_a * sizeof(int));
	if (tmp == NULL)
		return (FAIL);
	i = 0;
	while (i < stack->size_a)
		tmp[i++] = -1;
	index = 0;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] == get_lowest(stack->stack_a, tmp, stack))
		{
			stack->stack_a[i] = index;
			tmp[i] = index;
			index++;
		}
		i++;
	}
	return (free(tmp), tmp = NULL, SUCCESS);
}

static void	send_to(t_stack *stack, t_e_chunk from, t_e_chunk to, char **result)
{
	if (from == TOP_A && to == BOT_A)
		rotate(stack, 'a', result);
	if (from == TOP_A && to == TOP_B)
		push(stack, 'b', result);
	if (from == TOP_A && to == BOT_B)
	{
		push(stack, 'b', result);
		rotate(stack, 'b', result);
	}
	if (from == BOT_A && to == TOP_A)
		reverse_rotate(stack, 'a', result);
	if (from == BOT_A && to == TOP_B)
	{
		reverse_rotate(stack, 'a', result);
		push(stack, 'b', result);
	}
	if (from == BOT_A && to == BOT_B)
	{
		reverse_rotate(stack, 'a', result);
		push(stack, 'b', result);
		rotate(stack, 'b', result);
	}
}

static void	init_chunk(t_chunk *chunk, t_e_chunk from)
{
	if (from == TOP_A)
	{
		chunk->chunk = TOP_A;
		chunk->min->chunk = BOT_B;
		chunk->mid->chunk = TOP_B;
		chunk->max->chunk = BOT_A;
	}
	if (from == BOT_A)
	{
		chunk->chunk = BOT_A;
		chunk->min->chunk = BOT_B;
		chunk->mid->chunk = TOP_B;
		chunk->max->chunk = TOP_A;
	}
}

static void	set_range_chunk(t_chunk *chunks, int min, int max)
{
	chunks->min_range = min;
	chunks->max_range = max;
}

static void	split_chunk(t_chunk *chunk_to_sort, t_chunk *split_chunks,
		t_stack *stack, char **result)
{
	int	count;
	int	range_size;
	int	third;
	int	min_range;

	range_size = chunk_to_sort->max_range - chunk_to_sort->min_range;
	third = range_size / 3;
	min_range = chunk_to_sort->min_range;
	count = 0;
	while (count < range_size)
	{
		if (chunk_to_sort->chunk == TOP_A)
		{
			if (stack->stack_a[0] < min_range + third)
				send_to(stack, TOP_A, BOT_B, result);
			else if (stack->stack_a[0] < min_range + 2 * third)
				send_to(stack, TOP_A, TOP_B, result);
			else
				send_to(stack, TOP_A, BOT_A, result);
		}
		else if (chunk_to_sort->chunk == BOT_A)
		{
			if (stack->stack_a[stack->size_a - 1] < min_range + third)
				send_to(stack, BOT_A, BOT_B, result);
			else if (stack->stack_a[stack->size_a - 1] < min_range + 2 * third)
				send_to(stack, BOT_A, TOP_B, result);
			else
				send_to(stack, BOT_A, TOP_A, result);
		}
		count++;
	}
	set_range_chunk(split_chunks->min, min_range, min_range + third);
	set_range_chunk(split_chunks->mid, min_range + third, min_range + 2
		* third);
	set_range_chunk(split_chunks->max, min_range + 2 * third,
		chunk_to_sort->max_range);
	if (chunk_to_sort->chunk == TOP_A)
		init_chunk(split_chunks, BOT_A);
	else if (chunk_to_sort->chunk == BOT_A)
		init_chunk(split_chunks, TOP_A);
}

// static void	sort_two(t_chunk *chunk_to_sort, t_stack *stack)
// {
// 	if (chunk_to_sort->chunk == TOP_A)
// 	{
// 		if (stack->size_a >= 2 && stack->stack_a[0] > stack->stack_a[1])
// 			swap(stack, 'a');
// 	}
// 	else if (chunk_to_sort->chunk == BOT_A)
// 	{
// 		if (stack->size_a >= 2 && stack->stack_a[stack->size_a
// 			- 2] > stack->stack_a[stack->size_a - 1])
// 		{
// 			reverse_rotate(stack, 'a');
// 			reverse_rotate(stack, 'a');
// 			swap(stack, 'a');
// 			rotate(stack, 'a');
// 			rotate(stack, 'a');
// 		}
// 	}
// 	else if (chunk_to_sort->chunk == TOP_B)
// 	{
// 		if (stack->size_b >= 2 && stack->stack_b[0] < stack->stack_b[1])
// 			swap(stack, 'b');
// 	}
// 	else if (chunk_to_sort->chunk == BOT_B)
// 	{
// 		if (stack->size_b >= 2 && stack->stack_b[stack->size_b
// 			- 2] < stack->stack_b[stack->size_b - 1])
// 		{
// 			reverse_rotate(stack, 'b');
// 			reverse_rotate(stack, 'b');
// 			swap(stack, 'b');
// 			rotate(stack, 'b');
// 			rotate(stack, 'b');
// 		}
// 	}
// }

static void	sort_three_a(t_stack *stack, char **result)
{
	int	a;
	int	b;
	int	c;

	if (stack->size_a < 3)
		return ;
	a = stack->stack_a[0];
	b = stack->stack_a[1];
	c = stack->stack_a[2];
	if (a > b && b < c && a < c)
		swap(stack, 'a', result);
	else if (a > b && b > c)
	{
		swap(stack, 'a', result);
		reverse_rotate(stack, 'a', result);
	}
	else if (a > b && b < c && a > c)
		rotate(stack, 'a', result);
	else if (a < b && b > c && a < c)
	{
		swap(stack, 'a', result);
		rotate(stack, 'a', result);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, 'a', result);
}

static t_bool	malloc_chunk(t_chunk **split_chunks)
{
	*split_chunks = ft_calloc(1, sizeof(t_chunk));
	if (split_chunks == NULL)
		return (FAIL);
	(*split_chunks)->min = ft_calloc(1, sizeof(t_chunk));
	(*split_chunks)->mid = ft_calloc(1, sizeof(t_chunk));
	(*split_chunks)->max = ft_calloc(1, sizeof(t_chunk));
	if ((*split_chunks)->min == NULL || (*split_chunks)->mid == NULL
		|| (*split_chunks)->max == NULL)
	{
		free((*split_chunks)->min);
		free((*split_chunks)->mid);
		free((*split_chunks)->max);
		free((*split_chunks));
		return (FAIL);
	}
	return (SUCCESS);
}

static void	recursive_chunk(t_chunk *chunk_to_sort, t_stack *stack,
		char **result)
{
	t_chunk	*split_chunks;

	split_chunks = NULL;
	if (stack->size_a <= 3 || malloc_chunk(&split_chunks))
	{
		return ;
	}
	split_chunk(chunk_to_sort, split_chunks, stack, result);
	recursive_chunk(split_chunks->max, stack, result);
	recursive_chunk(split_chunks->mid, stack, result);
	recursive_chunk(split_chunks->min, stack, result);
	free(split_chunks->min);
	free(split_chunks->mid);
	free(split_chunks->max);
	free(split_chunks);
}

static void	free_all(t_stack stack, t_chunk *chunk, char *result)
{
	free(stack.stack_a);
	free(stack.stack_b);
	free(chunk->min);
	free(chunk->mid);
	free(chunk->max);
	free(chunk);
	free(result);
}

static void	init_struct(t_stack *stack, int *stack_a, int *stack_b)
{
	stack->size_a = 0;
	stack->size_b = 0;
	stack->stack_a = stack_a;
	stack->stack_b = stack_b;
}

static int	lowest_a(t_stack *stack)
{
	int	i;
	int	lowest;
	int	index;

	index = 0;
	lowest = INT_MAX;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < lowest)
		{
			lowest = stack->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static int	index_to_go(t_stack *stack, int nbr)
{
	int	next_nbr;
	int	size;
	int	i;

	size = stack->size_a;
	i = 0;
	if (nbr < stack->stack_a[lowest_a(stack)])
		return (lowest_a(stack));
	while (i < size)
	{
		if (i == size)
		{
			next_nbr = stack->stack_a[0];
		}
		else
			next_nbr = stack->stack_a[i + 1];
		if (nbr > stack->stack_a[i] && nbr < next_nbr)
			return (i + 1);
		i++;
	}
	return (INT_MAX);
}

static void	move_index(t_stack *stack, int index, char **result)
{
	int	index_a;
	int	i;

	index_a = index_to_go(stack, stack->stack_b[index]);
	i = 0;
	if (index_a < stack->size_a / 2)
	{
		while (i < index_a)
		{
			rotate(stack, 'a', result);
			i++;
		}
	}
	else
	{
		while (i < stack->size_a - index_a)
		{
			reverse_rotate(stack, 'a', result);
			i++;
		}
	}
	i = 0;
	if (index < stack->size_b / 2)
	{
		while (i < index)
		{
			rotate(stack, 'b', result);
			i++;
		}
	}
	else
	{
		while (i < stack->size_b - index)
		{
			reverse_rotate(stack, 'b', result);
			i++;
		}
	}
	push(stack, 'a', result);
}

static void	turkish_sort(t_stack *stack, char **result)
{
	int	lowest_move;
	int	index;
	int	size;
	int	i;
	int	move;

	while (stack->size_b > 0)
	{
		size = stack->size_b;
		i = 0;
		index = 0;
		lowest_move = INT_MAX;
		while (i < size)
		{
			if (i < size / 2)
			{
				if (index_to_go(stack, stack->stack_b[i]) < stack->size_a / 2)
					move = index_to_go(stack, stack->stack_b[i]) + i;
				else
					move = stack->size_a - index_to_go(stack, stack->stack_b[i])
						+ i;
			}
			else
			{
				if (index_to_go(stack, stack->stack_b[i]) < stack->size_a / 2)
					move = index_to_go(stack, stack->stack_b[i]) + (size - i);
				else
					move = stack->size_a - index_to_go(stack, stack->stack_b[i])
						+ (size - i);
			}
			if (move <= lowest_move)
			{
				lowest_move = move;
				index = i;
			}
			i++;
		}
		move_index(stack, index, result);
	}
}

static void	rotate_stack_a(t_stack *stack, char **result)
{
	int	index;
	int	i;

	index = lowest_a(stack);
	i = 0;
	if (index < stack->size_a / 2)
	{
		while (i < index)
		{
			rotate(stack, 'a', result);
			i++;
		}
	}
	else
	{
		while (i < stack->size_a - index)
		{
			reverse_rotate(stack, 'a', result);
			i++;
		}
	}
}

static void	delete_or_remplace(char **result, int operation)
{
	char	*start;
	char	*end;
	int		index;

	if (operation == 1)
	{
		index = ft_strnstr(*result, "\npa\npb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 8, ft_strlen(*result));
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 2)
	{
		index = ft_strnstr(*result, "\npb\npa\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 8, ft_strlen(*result));
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 3)
	{
		index = ft_strnstr(*result, "\nrb\nra\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 4, ft_strlen(*result));
		end[1] = 'r';
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 4)
	{
		index = ft_strnstr(*result, "\nra\nrb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 4, ft_strlen(*result));
		end[1] = 'r';
		free(*result);
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 5)
	{
		index = ft_strnstr(*result, "\nrrb\nrra\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 5, ft_strlen(*result));
		free(*result);
		end[2] = 'r';
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 6)
	{
		index = ft_strnstr(*result, "\nrra\nrrb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 5, ft_strlen(*result));
		free(*result);
		end[2] = 'r';
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 7)
	{
		index = ft_strnstr(*result, "\nrb\nrr\nra\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 4, ft_strlen(*result));
		free(*result);
		end[4] = 'r';
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 8)
	{
		index = ft_strnstr(*result, "\nra\nrr\nrb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 4, ft_strlen(*result));
		free(*result);
		end[4] = 'r';
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 9)
	{
		index = ft_strnstr(*result, "\nrrb\nrrr\nrra\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 5, ft_strlen(*result));
		free(*result);
		end[6] = 'r';
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
	if (operation == 10)
	{
		index = ft_strnstr(*result, "\nrra\nrrr\nrrb\n", ft_strlen(*result));
		start = ft_substr(*result, 0, index + 1);
		end = ft_substr(*result, index + 5, ft_strlen(*result));
		free(*result);
		end[6] = 'r';
		*result = ft_strjoin(start, end);
		free(start);
		free(end);
	}
}

static int	check_for_opti_result(char *result)
{
	if (ft_strnstr(result, "\npa\npb\n", ft_strlen(result)))
		return (1);
	else if (ft_strnstr(result, "\npb\npa\n", ft_strlen(result)))
		return (2);
	else if (ft_strnstr(result, "\nrb\nra\n", ft_strlen(result)))
		return (3);
	else if (ft_strnstr(result, "\nra\nrb\n", ft_strlen(result)))
		return (4);
	else if (ft_strnstr(result, "\nrrb\nrra\n", ft_strlen(result)))
		return (5);
	else if (ft_strnstr(result, "\nrra\nrrb\n", ft_strlen(result)))
		return (6);
	else if (ft_strnstr(result, "\nrb\nrr\nra\n", ft_strlen(result)))
		return (7);
	else if (ft_strnstr(result, "\nra\nrr\nrb\n", ft_strlen(result)))
		return (8);
	else if (ft_strnstr(result, "\nrrb\nrrr\nrra\n", ft_strlen(result)))
		return (9);
	else if (ft_strnstr(result, "\nrra\nrrr\nrrb\n", ft_strlen(result)))
		return (10);
	return (SUCCESS);
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
	int		*stack_a;
	int		*stack_b;
	t_stack	stack;
	t_chunk	*chunk;
	char	*result;

	result = NULL;
	stack_a = NULL;
	stack_b = NULL;
	init_struct(&stack, stack_a, stack_b);
	if (argc < 3)
		return (ft_printf("Error\n"), SUCCESS);
	if (check_argv(argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	if (malloc_chunk(&chunk))
		return (ft_printf("Error\n"), SUCCESS);
	init_chunk(chunk, TOP_A);
	if (malloc_init_stack(argc, argv, &stack))
		return (free_all(stack, chunk, result), ft_printf("Error\n"), SUCCESS);
	if (compress_value(&stack))
		return (free_all(stack, chunk, result), ft_printf("Error\n"), SUCCESS);
	set_range_chunk(chunk, 0, stack.size_a);
	recursive_chunk(chunk, &stack, &result);
	sort_three_a(&stack, &result);
	if (stack.size_b >= 1)
		turkish_sort(&stack, &result);
	rotate_stack_a(&stack, &result);
	clear_result(&result);
	ft_printf("%s", result);
	return (free_all(stack, chunk, result), SUCCESS);
}

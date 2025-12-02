/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/02 21:19:06 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	init_statck(int **stack_a, int argc, char *argv[],
		t_stack *size)
{
	int	content;
	int	i;
	int	j;

	*stack_a = malloc((argc - 1) * sizeof(int));
	if (*stack_a == NULL)
		return (FAIL);
	j = 1;
	while (j < argc)
	{
		content = ft_atoi(argv[j]);
		i = 0;
		while (i < size->size_a)
		{
			if (content == (*stack_a)[i++])
				return (FAIL);
		}
		(*stack_a)[size->size_a] = content;
		size->size_a++;
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

static t_bool	compress_value(int *stack_a, t_stack *stack)
{
	int	*tmp;
	int	i;
	int	index;

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
		if (stack_a[i] == get_lowest(stack_a, tmp, stack))
		{
			stack_a[i] = index;
			tmp[i] = index;
			index++;
		}
		i++;
	}
	return (free(tmp), tmp = NULL, SUCCESS);
}

static void	send_to(t_stack *stack, t_e_chunk from, t_e_chunk to)
{
	if (from == TOP_A && to == BOT_A)
		rotate(stack, 'a');
	if (from == TOP_A && to == TOP_B)
		push(stack, 'b');
	if (from == TOP_A && to == BOT_B)
	{
		push(stack, 'b');
		rotate(stack, 'b');
	}
	if (from == BOT_A && to == TOP_A)
		reverse_rotate(stack, 'a');
	if (from == BOT_A && to == TOP_B)
	{
		reverse_rotate(stack, 'a');
		push(stack, 'b');
	}
	if (from == BOT_A && to == BOT_B)
	{
		reverse_rotate(stack, 'a');
		push(stack, 'b');
		rotate(stack, 'b');
	}
	if (from == TOP_B && to == TOP_A)
		push(stack, 'a');
	if (from == TOP_B && to == BOT_B)
		rotate(stack, 'b');
	if (from == TOP_B && to == BOT_A)
	{
		push(stack, 'a');
		rotate(stack, 'a');
	}
	if (from == BOT_B && to == TOP_B)
		reverse_rotate(stack, 'b');
	if (from == BOT_B && to == TOP_A)
	{
		reverse_rotate(stack, 'b');
		push(stack, 'a');
	}
	if (from == BOT_B && to == BOT_A)
	{
		reverse_rotate(stack, 'b');
		push(stack, 'a');
		rotate(stack, 'a');
	}
}

static void	split_chunk(t_chunk *chunk_to_sort, t_chunk *split_chunks,
		t_stack *stack)
{
	int	count;
	int	range_size;
	int	third;

	count = 0;
	range_size = chunk_to_sort->max_range - chunk_to_sort->min_range;
	third = range_size / 3;
	/* Process all elements in this chunk, sorting them to 3 sub-chunks */
	while (count < range_size)
	{
		if (chunk_to_sort->chunk == TOP_A)
		{
			if (stack->stack_a[0] < chunk_to_sort->min_range + third)
				send_to(stack, TOP_A, BOT_B);
			else if (stack->stack_a[0] < chunk_to_sort->min_range + 2 * third)
				send_to(stack, TOP_A, TOP_B);
			else
				send_to(stack, TOP_A, BOT_A);
		}
		else if (chunk_to_sort->chunk == BOT_A)
		{
			if (stack->stack_a[stack->size_a - 1] < chunk_to_sort->min_range
				+ third)
				send_to(stack, BOT_A, BOT_B);
			else if (stack->stack_a[stack->size_a
				- 1] < chunk_to_sort->min_range + 2 * third)
				send_to(stack, BOT_A, TOP_B);
			else
				send_to(stack, BOT_A, TOP_A);
		}
		else if (chunk_to_sort->chunk == TOP_B)
		{
			if (stack->stack_b[0] < chunk_to_sort->min_range + third)
				send_to(stack, TOP_B, BOT_B);
			else if (stack->stack_b[0] < chunk_to_sort->min_range + 2 * third)
				send_to(stack, TOP_B, BOT_A);
			else
				send_to(stack, TOP_B, TOP_A);
		}
		else if (chunk_to_sort->chunk == BOT_B)
		{
			if (stack->stack_b[stack->size_b - 1] < chunk_to_sort->min_range
				+ third)
				send_to(stack, BOT_B, TOP_B);
			else if (stack->stack_b[stack->size_b
				- 1] < chunk_to_sort->min_range + 2 * third)
				send_to(stack, BOT_B, BOT_A);
			else
				send_to(stack, BOT_B, TOP_A);
		}
		count++;
	}
	/* Setup sub-chunks for next recursion */
	split_chunks->min->min_range = chunk_to_sort->min_range;
	split_chunks->min->max_range = chunk_to_sort->min_range + third;
	split_chunks->min->min = NULL;
	split_chunks->min->mid = NULL;
	split_chunks->min->max = NULL;
	split_chunks->mid->min_range = chunk_to_sort->min_range + third;
	split_chunks->mid->max_range = chunk_to_sort->min_range + 2 * third;
	split_chunks->mid->min = NULL;
	split_chunks->mid->mid = NULL;
	split_chunks->mid->max = NULL;
	split_chunks->max->min_range = chunk_to_sort->min_range + 2 * third;
	split_chunks->max->max_range = chunk_to_sort->max_range;
	split_chunks->max->min = NULL;
	split_chunks->max->mid = NULL;
	split_chunks->max->max = NULL;
	if (chunk_to_sort->chunk == TOP_A)
	{
		split_chunks->chunk = BOT_A;
		split_chunks->min->chunk = BOT_B;
		split_chunks->mid->chunk = TOP_B;
		split_chunks->max->chunk = TOP_A;
	}
	else if (chunk_to_sort->chunk == BOT_A)
	{
		split_chunks->chunk = TOP_B;
		split_chunks->min->chunk = BOT_B;
		split_chunks->mid->chunk = TOP_A;
		split_chunks->max->chunk = BOT_A;
	}
	else if (chunk_to_sort->chunk == TOP_B)
	{
		split_chunks->chunk = BOT_B;
		split_chunks->min->chunk = TOP_B;
		split_chunks->mid->chunk = BOT_A;
		split_chunks->max->chunk = TOP_A;
	}
	else if (chunk_to_sort->chunk == BOT_B)
	{
		split_chunks->chunk = TOP_A;
		split_chunks->min->chunk = BOT_B;
		split_chunks->mid->chunk = TOP_B;
		split_chunks->max->chunk = BOT_A;
	}
}

static void	sort_two(t_chunk *chunk_to_sort, t_stack *stack)
{
	if (chunk_to_sort->chunk == TOP_A)
	{
		if (stack->size_a >= 2 && stack->stack_a[0] > stack->stack_a[1])
			swap(stack, 'a');
	}
	else if (chunk_to_sort->chunk == BOT_A)
	{
		if (stack->size_a >= 2 && stack->stack_a[stack->size_a
			- 2] > stack->stack_a[stack->size_a - 1])
		{
			reverse_rotate(stack, 'a');
			reverse_rotate(stack, 'a');
			swap(stack, 'a');
			rotate(stack, 'a');
			rotate(stack, 'a');
		}
	}
	else if (chunk_to_sort->chunk == TOP_B)
	{
		if (stack->size_b >= 2 && stack->stack_b[0] < stack->stack_b[1])
			swap(stack, 'b');
	}
	else if (chunk_to_sort->chunk == BOT_B)
	{
		if (stack->size_b >= 2 && stack->stack_b[stack->size_b
			- 2] < stack->stack_b[stack->size_b - 1])
		{
			reverse_rotate(stack, 'b');
			reverse_rotate(stack, 'b');
			swap(stack, 'b');
			rotate(stack, 'b');
			rotate(stack, 'b');
		}
	}
}

// static void	sort_three(t_chunk *chunk_to_sort, t_stack *stack)
// {
// 	int a, b, c;
// 	if (chunk_to_sort->chunk == TOP_A)
// 	{
// 		if (stack->size_a < 3)
// 			return ;
// 		a = stack->stack_a[0];
// 		b = stack->stack_a[1];
// 		c = stack->stack_a[2];
// 		if (a > b && b < c && a < c)
// 			swap(stack, 'a');
// 		else if (a > b && b > c)
// 		{
// 			swap(stack, 'a');
// 			reverse_rotate(stack, 'a');
// 		}
// 		else if (a > b && b < c && a > c)
// 			rotate(stack, 'a');
// 		else if (a < b && b > c && a < c)
// 		{
// 			swap(stack, 'a');
// 			rotate(stack, 'a');
// 		}
// 		else if (a < b && b > c && a > c)
// 			reverse_rotate(stack, 'a');
// 	}
// 	else if (chunk_to_sort->chunk == BOT_A)
// 	{
// 		if (stack->size_a < 3)
// 			return ;
// 		/* bring bottom-3 to top preserving order */
// 		reverse_rotate(stack, 'a');
// 		reverse_rotate(stack, 'a');
// 		reverse_rotate(stack, 'a');
// 		/* sort top three as TOP_A */
// 		chunk_to_sort->chunk = TOP_A;
// 		sort_three(chunk_to_sort, stack);
// 		chunk_to_sort->chunk = BOT_A;
// 		/* send them back */
// 		rotate(stack, 'a');
// 		rotate(stack, 'a');
// 		rotate(stack, 'a');
// 	}
// 	else if (chunk_to_sort->chunk == TOP_B)
// 	{
// 		if (stack->size_b < 3)
// 			return ;
// 		a = stack->stack_b[0];
// 		b = stack->stack_b[1];
// 		c = stack->stack_b[2];
// 		/* For stack B we want descending order */
// 		if (a < b && b > c && a > c)
// 			swap(stack, 'b');
// 		else if (a < b && b < c)
// 		{
// 			swap(stack, 'b');
// 			reverse_rotate(stack, 'b');
// 		}
// 		else if (a < b && b > c && a < c)
// 			rotate(stack, 'b');
// 		else if (a > b && b < c && a > c)
// 		{
// 			swap(stack, 'b');
// 			rotate(stack, 'b');
// 		}
// 		else if (a > b && b < c && a < c)
// 			reverse_rotate(stack, 'b');
// 	}
// 	else if (chunk_to_sort->chunk == BOT_B)
// 	{
// 		if (stack->size_b < 3)
// 			return ;
// 		reverse_rotate(stack, 'b');
// 		reverse_rotate(stack, 'b');
// 		reverse_rotate(stack, 'b');
// 		chunk_to_sort->chunk = TOP_B;
// 		sort_three(chunk_to_sort, stack);
// 		chunk_to_sort->chunk = BOT_B;
// 		rotate(stack, 'b');
// 		rotate(stack, 'b');
// 		rotate(stack, 'b');
// 	}
// }

static void	perform_very_simple_sort(t_chunk *chunk_to_sort, t_stack *stack,
		int size)
{
	int	i;

	// if (stack->size_a == 3 || size == 3)
	// {
	// 	ft_printf("test3 %i =====================================\n",
	// 		chunk_to_sort->chunk);
	// 	sort_three(chunk_to_sort, stack);
	// }
	if (stack->size_a == 2 || size == 2)
	{
		ft_printf("test2 %i =====================================\n",
			chunk_to_sort->chunk);
		sort_two(chunk_to_sort, stack);
	}
	/* If the chunk is on stack B,
		after sorting we must push elements back to A */
	if ((chunk_to_sort->chunk == TOP_B || chunk_to_sort->chunk == BOT_B)
		&& size > 0)
	{
		i = 0;
		if (chunk_to_sort->chunk == BOT_B)
		{
			/* bring bottom elements to top one by one then push */
			while (i < size)
			{
				reverse_rotate(stack, 'b');
				push(stack, 'a');
				if (stack->stack_a[0] != stack->stack_a[1] - 1)
					rotate(stack, 'a');
				i++;
			}
		}
		else
		{
			while (i < size)
			{
				push(stack, 'a');
				if (stack->stack_a[0] != stack->stack_a[1] - 1)
				{
					rotate(stack, 'a');
					ft_printf("reverse_rotate %i\n", chunk_to_sort->chunk);
				}
				i++;
			}
		}
	}
	// index--;
}

static void	recursive_chunk_sort(t_chunk *chunk_to_sort, t_stack *stack)
{
	t_chunk	*split_chunks;

	/* Base case: if chunk is small enough, stop recursion */
	if (chunk_to_sort->max_range - chunk_to_sort->min_range <= 2)
	{
		perform_very_simple_sort(chunk_to_sort, stack, chunk_to_sort->max_range
			- chunk_to_sort->min_range);
		return ;
	}
	split_chunks = malloc(sizeof(t_chunk));
	if (split_chunks == NULL)
		return ;
	split_chunks->min = malloc(sizeof(t_chunk));
	split_chunks->mid = malloc(sizeof(t_chunk));
	split_chunks->max = malloc(sizeof(t_chunk));
	/* ensure allocated memory is zeroed to avoid using uninitialized fields */
	if (split_chunks->min)
		ft_bzero(split_chunks->min, sizeof(t_chunk));
	if (split_chunks->mid)
		ft_bzero(split_chunks->mid, sizeof(t_chunk));
	if (split_chunks->max)
		ft_bzero(split_chunks->max, sizeof(t_chunk));
	if (split_chunks->min == NULL || split_chunks->mid == NULL
		|| split_chunks->max == NULL)
	{
		free(split_chunks->min);
		free(split_chunks->mid);
		free(split_chunks->max);
		free(split_chunks);
		return ;
	}
	split_chunk(chunk_to_sort, split_chunks, stack);
	recursive_chunk_sort(split_chunks->max, stack);
	recursive_chunk_sort(split_chunks->mid, stack);
	recursive_chunk_sort(split_chunks->min, stack);
	free(split_chunks->min);
	free(split_chunks->mid);
	free(split_chunks->max);
	free(split_chunks);
}

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	t_stack	stack;
	int		i;
	t_chunk	chunk;

	stack.size_a = 0;
	stack.size_b = 0;
	if (argc == 1)
		return (SUCCESS);
	if (check_argv(argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	if (init_statck(&stack_a, argc, argv, &stack))
		return (free(stack_a), ft_printf("Error\n"), SUCCESS);
	stack_b = malloc((argc - 1) * sizeof(int));
	if (stack_b == NULL)
		return (free(stack_a), SUCCESS);
	if (compress_value(stack_a, &stack))
		return (free(stack_a), free(stack_b), SUCCESS);
	i = 0;
	chunk.chunk = TOP_A;
	chunk.min_range = 0;
	chunk.max_range = stack.size_a;
	chunk.min = NULL;
	chunk.mid = NULL;
	chunk.max = NULL;
	stack.stack_a = stack_a;
	stack.stack_b = stack_b;
	recursive_chunk_sort(&chunk, &stack);
	// while (i < stack.size_a)
	// 	ft_printf("%i\n", stack_a[i++]);
	free(stack_a);
	free(stack_b);
}

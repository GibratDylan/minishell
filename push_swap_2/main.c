/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/05 16:44:38 by dgibrat          ###   ########.fr       */
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

// static void	sort_three(t_stack *stack)
// {
// 	int a, b, c;
// 	if (stack->size_a < 3)
// 		return ;
// 	a = stack->stack_a[0];
// 	b = stack->stack_a[1];
// 	c = stack->stack_a[2];
// 	if (a > b && b < c && a < c)
// 		swap(stack, 'a');
// 	else if (a > b && b > c)
// 	{
// 		swap(stack, 'a');
// 		reverse_rotate(stack, 'a');
// 	}
// 	else if (a > b && b < c && a > c)
// 		rotate(stack, 'a');
// 	else if (a < b && b > c && a < c)
// 	{
// 		swap(stack, 'a');
// 		rotate(stack, 'a');
// 	}
// 	else if (a < b && b > c && a > c)
// 		reverse_rotate(stack, 'a');
// }

// static int	biggest_content(int *stack, int size)
// {
// 	int	biggest;
// 	int	result;
// 	int	i;

// 	biggest = INT_MIN;
// 	result = 0;
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (biggest < stack[i])
// 		{
// 			biggest = stack[i];
// 			result = i;
// 		}
// 		i++;
// 	}
// 	return (result);
// }

static void		recursive_chunk_sort_a(t_stack *stack, int median);

static void	recursive_chunk_sort_b(t_stack *stack, int len)
{
	int	size;
	int	i;
	int	median;

	if (len <= 3)
	{
		ft_printf("end b\n");
		return ;
	}
	i = 0;
	median = (((len / 2) - 1) + (len / 2)) / 2;
	size = stack->size_b;
	while (i < size)
	{
		if (stack->stack_b[i] > median)
			push(stack, 'a');
		else
			rotate(stack, 'b');
		i++;
	}
	recursive_chunk_sort_a(stack, len / 2);
	recursive_chunk_sort_b(stack, len / 2);
}

static void	recursive_chunk_sort_a(t_stack *stack, int len)
{
	int	size;
	int	i;
	int	median;

	if (len <= 3)
	{
		ft_printf("end a\n");
		return ;
	}
	i = 0;
	median = (((len / 2) - 1) + (len / 2)) / 2;
	size = stack->size_a;
	while (i < size)
	{
		if (stack->stack_a[i] < median)
			push(stack, 'b');
		else
			rotate(stack, 'a');
		i++;
	}
	recursive_chunk_sort_a(stack, len / 2);
	recursive_chunk_sort_b(stack, stack->size_b);
}

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	t_stack	stack;

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
	stack.stack_a = stack_a;
	stack.stack_b = stack_b;
	recursive_chunk_sort_a(&stack, stack.size_a);
	// while (i < stack.size_a)
	// 	ft_printf("%i\n", stack_a[i++]);
	free(stack_a);
	free(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:47:00 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/08 19:22:39 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_argv(int argc, char *argv[])
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

int	get_lowest(int *tmp, t_stack *stack)
{
	int	i;
	int	lowest;

	lowest = INT_MAX;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < lowest && tmp[i] == -1)
			lowest = stack->stack_a[i];
		i++;
	}
	return (lowest);
}

t_bool	compress_value(t_stack *stack)
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
		if (stack->stack_a[i] == get_lowest(tmp, stack) && tmp[i] == -1)
		{
			stack->stack_a[i] = index;
			tmp[i] = 0;
			index++;
			i = -1;
		}
		i++;
	}
	return (free(tmp), tmp = NULL, SUCCESS);
}

t_bool	is_not_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

void	free_all(t_stack stack, t_chunk *chunk, char *result)
{
	free(stack.stack_a);
	free(stack.stack_b);
	free(chunk->min);
	free(chunk->mid);
	free(chunk->max);
	free(chunk);
	free(result);
}

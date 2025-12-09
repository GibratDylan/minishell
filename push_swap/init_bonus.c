/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:39:38 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 17:19:52 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_b->stack);
}

t_bool	init_struct_circular_buffer(t_stack *stack_a, t_stack *stack_b,
		int size)
{
	stack_a->stack = malloc(size * sizeof(int));
	if (!stack_a->stack)
		return (free_all(stack_a, stack_b), FAIL);
	stack_b->stack = malloc(size * sizeof(int));
	if (!stack_b->stack)
		return (free_all(stack_a, stack_b), FAIL);
	stack_a->top = 0;
	stack_a->size = 0;
	stack_a->cap = size;
	stack_b->top = 0;
	stack_b->size = 0;
	stack_b->cap = size;
	return (SUCCESS);
}

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

t_bool	set_stack(t_all_stack *stack, int argc, char *argv[])
{
	int		content;
	size_t	i;
	int		j;

	j = 0;
	while (j + 1 < argc)
	{
		content = ft_atoi(argv[j + 1]);
		i = 0;
		while (i < stack->stack_a->size)
		{
			if (content == stack->stack_a->stack[i++])
				return (FAIL);
		}
		stack->stack_a->stack[j] = content;
		stack->stack_a->size++;
		j++;
	}
	return (SUCCESS);
}

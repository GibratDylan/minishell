/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:40:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/08 18:53:17 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	malloc_init_stack(int argc, char *argv[], t_stack *stack)
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

void	init_chunk(t_chunk *chunk, t_e_chunk from)
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

void	init_struct(t_stack *stack, int *stack_a, int *stack_b)
{
	stack->size_a = 0;
	stack->size_b = 0;
	stack->stack_a = stack_a;
	stack->stack_b = stack_b;
}

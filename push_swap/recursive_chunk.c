/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:45:05 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 12:23:59 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	send_to(t_stack *stack, t_e_chunk from, t_e_chunk to, char **result)
{
	if (from == TOP_A && to == BOT_A && rotate_a(stack, result))
		return (FAIL);
	if (from == TOP_A && to == TOP_B && push_b(stack, result))
		return (FAIL);
	if (from == TOP_A && to == BOT_B && (push_b(stack, result)
			|| rotate_b(stack, result)))
		return (FAIL);
	if (from == BOT_A && to == TOP_A && reverse_rotate_a(stack, result))
		return (FAIL);
	if (from == BOT_A && to == TOP_B && (reverse_rotate_a(stack, result)
			|| push_b(stack, result)))
		return (FAIL);
	if (from == BOT_A && to == BOT_B && (reverse_rotate_a(stack, result)
			|| push_b(stack, result) || rotate_b(stack, result)))
		return (FAIL);
	return (SUCCESS);
}

void	set_range_chunk(t_chunk *chunks, int min, int max)
{
	chunks->min_range = min;
	chunks->max_range = max;
}

t_bool	split_chunk(t_chunk *chunk_to_sort, t_chunk *split_chunks,
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
			if (check_where_to_send_from_top_a(stack, min_range, third, result))
				return (FAIL);
		}
		else if (chunk_to_sort->chunk == BOT_A)
		{
			if (check_where_to_send_from_bot_a(stack, min_range, third, result))
				return (FAIL);
		}
		count++;
	}
	set_chunk(split_chunks, chunk_to_sort, min_range, third);
	return (SUCCESS);
}

t_bool	malloc_chunk(t_chunk **split_chunks)
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

t_bool	recursive_chunk(t_chunk *chunk_to_sort, t_stack *stack, char **result)
{
	t_chunk	*split_chunks;

	split_chunks = NULL;
	if (stack->size_a <= 3)
		return (SUCCESS);
	if (malloc_chunk(&split_chunks))
		return (FAIL);
	split_chunk(chunk_to_sort, split_chunks, stack, result);
	if (recursive_chunk(split_chunks->max, stack, result)
		|| recursive_chunk(split_chunks->mid, stack, result)
		|| recursive_chunk(split_chunks->min, stack, result))
		return (free(split_chunks->min), free(split_chunks->mid),
			free(split_chunks->max), free(split_chunks), FAIL);
	free(split_chunks->min);
	free(split_chunks->mid);
	free(split_chunks->max);
	free(split_chunks);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_chunk_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:00 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 12:24:05 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_where_to_send_from_top_a(t_stack *stack, int min_range, int third,
		char **result)
{
	if (stack->stack_a[0] < min_range + third)
	{
		if (send_to(stack, TOP_A, BOT_B, result))
			return (FAIL);
	}
	else if (stack->stack_a[0] < min_range + 2 * third)
	{
		if (send_to(stack, TOP_A, TOP_B, result))
			return (FAIL);
	}
	else
	{
		if (send_to(stack, TOP_A, BOT_A, result))
			return (FAIL);
	}
	return (SUCCESS);
}

t_bool	check_where_to_send_from_bot_a(t_stack *stack, int min_range, int third,
		char **result)
{
	if (stack->stack_a[stack->size_a - 1] < min_range + third)
	{
		if (send_to(stack, BOT_A, BOT_B, result))
			return (FAIL);
	}
	else if (stack->stack_a[stack->size_a - 1] < min_range + 2 * third)
	{
		if (send_to(stack, BOT_A, TOP_B, result))
			return (FAIL);
	}
	else
	{
		if (send_to(stack, BOT_A, TOP_A, result))
			return (FAIL);
	}
	return (SUCCESS);
}

void	set_chunk(t_chunk *split_chunks, t_chunk *chunk_to_sort, int min_range,
		int third)
{
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

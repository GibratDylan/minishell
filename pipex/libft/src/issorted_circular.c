/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted_circular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:36:08 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/16 15:22:54 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_bool	issorted_sorted(t_stack *stack)
{
	int	i;
	int	idx1;
	int	idx2;

	if (!stack)
		return (FAIL);
	i = 0;
	while (i < stack->size - 1)
	{
		idx1 = next_circular(stack, i, stack->cap);
		idx2 = next_circular(stack, i + 1, stack->cap);
		if (stack->stack[idx1] > stack->stack[idx2])
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

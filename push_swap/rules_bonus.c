/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:09:47 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 16:23:17 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_all_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	rotate(t_all_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void	reverse_rotate(t_all_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}

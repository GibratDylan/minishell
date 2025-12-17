/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_circular.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:29:22 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/16 15:23:51 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	next_circular(t_stack *stack, int nbr, int cap)
{
	return ((stack->top + nbr) % cap);
}

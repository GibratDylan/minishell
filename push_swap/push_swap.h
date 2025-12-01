/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:22 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/01 12:52:32 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define SUCCESS 0
# define FAIL 1

void	swap(t_list *stack, char stack_c);
void	push(t_list **stack_from, t_list **stack_to, char stack_c);
void	swap_s(t_list *stack_a, t_list *stack_b);
void	rotate(t_list *stack, char stack_c);
void	rotate_r(t_list *stack_a, t_list *stack_b);
void	reverse_rotate(t_list *stack, char stack_c);
void	reverse_rotate_r(t_list *stack_a, t_list *stack_b);

#endif
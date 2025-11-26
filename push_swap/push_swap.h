/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:22 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/26 18:46:48 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define SUCCESS 0
# define FAIL 1

void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	swap_s(t_list *stack_a, t_list *stack_b);
void	reverse_rotate_a(t_list *stack_a);
void	reverse_rotate_b(t_list *stack_b);
void	reverse_rotate_r(t_list *stack_a, t_list *stack_b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:32:45 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 16:23:41 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*stack;
	size_t	top;
	size_t	size;
	size_t	cap;

}			t_stack;

typedef struct s_all_stack
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_all_stack;

t_bool		init_struct_circular_buffer(t_stack *stack_a, t_stack *stack_b,
				int size);
t_bool		check_argv(int argc, char *argv[]);
t_bool		set_stack(t_all_stack *stack, int argc, char *argv[]);
void		sort_with_operation(t_all_stack *stack, char **operation);
void		free_all(t_stack *stack_a, t_stack *stack_b);
void		swap_a(t_all_stack *stack);
void		swap_b(t_all_stack *stack);
void		swap(t_all_stack *stack);
void		push_a(t_all_stack *stack);
void		push_b(t_all_stack *stack);
void		rotate_a(t_all_stack *stack);
void		rotate_b(t_all_stack *stack);
void		rotate(t_all_stack *stack);
void		reverse_rotate_a(t_all_stack *stack);
void		reverse_rotate_b(t_all_stack *stack);
void		reverse_rotate(t_all_stack *stack);
t_bool		is_not_sorted(t_all_stack *stack);

#endif
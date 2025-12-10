/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:32:45 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 14:42:48 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*stack;
	int		top;
	int		size;
	int		cap;

}			t_stack;

typedef struct s_all_stack
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_all_stack;

int			next_circular(t_stack *stack, int nbr, int cap);
int			prev_circular(t_stack *stack, int nbr, int cap);
t_bool		init_circular(t_stack *stack_a, t_stack *stack_b, int size);
t_bool		check_argv(int argc, char *argv[]);
t_bool		set_stack(t_all_stack *stack, int argc, char *argv[]);
void		sort_with_operation(t_all_stack *stack, char **operation);
void		free_all(t_all_stack *stack, char **argv);
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
void		read_stdin(char **result);

#endif
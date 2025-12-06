/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:22 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/06 18:58:09 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define SUCCESS 0
# define FAIL 1

typedef struct s_stack
{
	int				*stack_a;
	int				*stack_b;
	int				size_a;
	int				size_b;
}					t_stack;

typedef enum e_chunk
{
	BOT_B,
	TOP_B,
	BOT_A,
	TOP_A
}					t_e_chunk;

typedef struct s_chunk
{
	t_e_chunk		chunk;
	struct s_chunk	*min;
	struct s_chunk	*mid;
	struct s_chunk	*max;
	int				min_range;
	int				max_range;
}					t_chunk;

void				swap(t_stack *stack, char stack_c, char **result);
void				push(t_stack *stack, char stack_c, char **result);
void				rotate(t_stack *stack, char stack_c, char **result);
void				reverse_rotate(t_stack *stack, char stack_c, char **result);

#endif
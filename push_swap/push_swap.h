/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:22 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 14:29:43 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

t_bool				swap_a(t_stack *stack, char **result);
t_bool				push_a(t_stack *stack, char **result);
t_bool				push_b(t_stack *stack, char **result);
t_bool				rotate_a(t_stack *stack, char **result);
t_bool				rotate_b(t_stack *stack, char **result);
t_bool				reverse_rotate_a(t_stack *stack, char **result);
t_bool				reverse_rotate_b(t_stack *stack, char **result);
t_bool				check_argv(int argc, char *argv[]);
int					get_lowest(int *tmp, t_stack *stack);
t_bool				compress_value(t_stack *stack);
t_bool				is_not_sorted(t_stack *stack);
void				free_all(t_stack stack, t_chunk *chunk, char *result,
						char **argv);
int					lowest_a(t_stack *stack);
int					index_to_go(t_stack *stack, int nbr);
t_bool				move_index(t_stack *stack, int index, char **result);
t_bool				turkish_sort(t_stack *stack, char **result);
t_bool				send_to(t_stack *stack, t_e_chunk from, t_e_chunk to,
						char **result);
void				set_range_chunk(t_chunk *chunks, int min, int max);
t_bool				split_chunk(t_chunk *chunk_to_sort, t_chunk *split_chunks,
						t_stack *stack, char **result);
t_bool				malloc_chunk(t_chunk **split_chunks);
t_bool				recursive_chunk(t_chunk *chunk_to_sort, t_stack *stack,
						char **result);
t_bool				sort_algo(t_stack *stack, t_chunk *chunk, char **result);
t_bool				rotate_stack_a(t_stack *stack, char **result);
t_bool				sort_two_a(t_stack *stack, char **result);
t_bool				sort_three_a(t_stack *stack, char **result);
t_bool				malloc_init_stack(int argc, char *argv[], t_stack *stack);
void				init_chunk(t_chunk *chunk, t_e_chunk from);
void				init_struct(t_stack *stack, int *stack_a, int *stack_b);
t_bool				move_to_index_a(t_stack *stack, int index, char **result);
t_bool				move_to_index_b(t_stack *stack, int index, char **result);
int					count_move(t_stack *stack, int index);
t_bool				check_where_to_send_from_top_a(t_stack *stack,
						int min_range, int third, char **result);
t_bool				check_where_to_send_from_bot_a(t_stack *stack,
						int min_range, int third, char **result);
void				set_chunk(t_chunk *split_chunks, t_chunk *chunk_to_sort,
						int min_range, int third);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/08 19:22:25 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	t_stack	stack;
	t_chunk	*chunk;
	char	*result;

	result = NULL;
	stack_a = NULL;
	stack_b = NULL;
	init_struct(&stack, stack_a, stack_b);
	if (argc < 3 || check_argv(argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	if (malloc_chunk(&chunk))
		return (ft_printf("Error\n"), SUCCESS);
	if (malloc_init_stack(argc, argv, &stack) || compress_value(&stack))
		return (free_all(stack, chunk, result), ft_printf("Error\n"), SUCCESS);
	init_chunk(chunk, TOP_A);
	set_range_chunk(chunk, 0, stack.size_a);
	if (sort_algo(&stack, chunk, &result))
		return (free_all(stack, chunk, result), ft_printf("Error\n"), SUCCESS);
	if (result)
		ft_printf("%s", result);
	return (free_all(stack, chunk, result), SUCCESS);
}

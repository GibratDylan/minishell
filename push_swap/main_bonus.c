/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:31:58 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 11:49:39 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_all_stack	stack;
	char		*result;
	char		**operation;

	if (argc < 3 || check_argv(argc, argv)
		|| init_struct_circular_buffer(&stack_a, &stack_b, argc - 1))
		return (ft_putstr_fd("Error\n", 2), SUCCESS);
	stack.stack_a = &stack_a;
	stack.stack_b = &stack_b;
	if (set_stack(&stack, argc, argv))
		return (free_all(&stack), ft_putstr_fd("Error\n", 2), SUCCESS);
	read_stdin(&result);
	operation = ft_split(result, '\n');
	if (!operation)
		return (free_all(&stack), free(result), ft_putstr_fd("Error\n", 2),
			FAIL);
	sort_with_operation(&stack, operation);
	ft_free_array(operation);
	if (is_not_sorted(&stack) || stack.stack_b->size > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (free_all(&stack), free(result), SUCCESS);
}

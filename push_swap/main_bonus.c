/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:31:58 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/09 17:40:57 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_all_stack	stack;
	char		buffer[2];
	int			size_read;
	char		*tmp;
	char		*result;
	char		**operation;

	if (argc < 3 || check_argv(argc, argv))
		return (ft_printf("Error\n"), SUCCESS);
	if (init_struct_circular_buffer(&stack_a, &stack_b, argc - 1))
		return (ft_printf("Error\n"), SUCCESS);
	stack.stack_a = &stack_a;
	stack.stack_b = &stack_b;
	if (set_stack(&stack, argc, argv))
		return (free_all(stack.stack_a, stack.stack_b), ft_printf("Error\n"),
			SUCCESS);
	size_read = 1;
	result = NULL;
	while (size_read > 0)
	{
		size_read = read(0, buffer, 1);
		if (size_read < 0)
			return (0);
		buffer[size_read] = '\0';
		tmp = ft_strjoin(result, buffer);
		if (tmp == NULL)
			return (0);
		free(result);
		result = tmp;
	}
	operation = ft_split(result, '\n');
	if (!operation)
		return (free_all(stack.stack_a, stack.stack_b), ft_printf("Error\n"),
			FAIL);
	sort_with_operation(&stack, operation);
	ft_free_array(operation);
	if (is_not_sorted(&stack) || stack.stack_b->size > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (free_all(stack.stack_a, stack.stack_b), SUCCESS);
}

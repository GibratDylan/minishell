/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:31:58 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 14:42:33 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	get_string(int *argc, char ***argv)
{
	char	**tmp;
	int		i;

	if (*argc == 2)
	{
		tmp = ft_split((*argv)[1], ' ');
		*argv = tmp;
		i = 0;
		while ((*argv)[i])
			i++;
		*argc = i;
	}
	else
	{
		tmp = malloc(*argc * sizeof(char *));
		(*argc)--;
		i = 0;
		while (i < *argc)
		{
			tmp[i] = ft_strdup((*argv)[i + 1]);
			i++;
		}
		tmp[i] = NULL;
		*argv = tmp;
	}
}

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_all_stack	stack;
	char		*result;
	char		**operation;

	get_string(&argc, &argv);
	if (check_argv(argc, argv) || init_circular(&stack_a, &stack_b, argc))
		return (ft_putstr_fd("Error\n", 2), SUCCESS);
	stack.stack_a = &stack_a;
	stack.stack_b = &stack_b;
	if (set_stack(&stack, argc, argv))
		return (free_all(&stack, argv), ft_putstr_fd("Error\n", 2), SUCCESS);
	read_stdin(&result);
	operation = ft_split(result, '\n');
	if (!operation)
		return (free_all(&stack, argv), free(result), ft_putstr_fd("Error\n",
				2), FAIL);
	sort_with_operation(&stack, operation);
	ft_free_array(operation);
	if (is_not_sorted(&stack) || stack.stack_b->size > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (free_all(&stack, argv), free(result), SUCCESS);
}

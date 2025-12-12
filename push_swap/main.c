/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/12 16:44:41 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
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
	get_string(&argc, &argv);
	if (check_argv(argc, argv) || malloc_chunk(&chunk))
		return (ft_free_array(argv), ft_putstr_fd("Error\n", 2), SUCCESS);
	if (malloc_init_stack(argc, argv, &stack) || compress_value(&stack))
		return (free_all(stack, chunk, result, argv), ft_putstr_fd("Error\n",
				2), SUCCESS);
	init_chunk(chunk, TOP_A);
	set_range_chunk(chunk, 0, stack.size_a);
	if (sort_algo(&stack, chunk, &result))
		return (free_all(stack, chunk, result, argv), ft_putstr_fd("Error\n",
				2), SUCCESS);
	if (result)
		ft_printf("%s", result);
	return (free_all(stack, chunk, result, argv), SUCCESS);
}

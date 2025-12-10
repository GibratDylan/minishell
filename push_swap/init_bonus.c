/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:39:38 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 15:16:06 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(t_all_stack *stack, char **argv)
{
	free(stack->stack_a->stack);
	free(stack->stack_b->stack);
	ft_free_array(argv);
}

t_bool	init_circular(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->stack = malloc(size * sizeof(int));
	if (!stack_a->stack)
		return (FAIL);
	stack_b->stack = malloc(size * sizeof(int));
	if (!stack_b->stack)
		return (free(stack_a->stack), FAIL);
	stack_a->top = 0;
	stack_a->size = 0;
	stack_a->cap = size;
	stack_b->top = 0;
	stack_b->size = 0;
	stack_b->cap = size;
	return (SUCCESS);
}

t_bool	check_argv(int argc, char *argv[])
{
	char	*result;
	int		i;

	i = 0;
	while (i < argc)
	{
		result = ft_itoa(ft_atoi(argv[i]));
		if (result == NULL)
			return (FAIL);
		if (ft_strncmp(argv[i], result, ft_strlen(argv[i])))
			return (free(result), FAIL);
		free(result);
		i++;
	}
	return (SUCCESS);
}

t_bool	set_stack(t_all_stack *stack, int argc, char *argv[])
{
	int	content;
	int	i;
	int	j;

	j = 0;
	while (j < argc)
	{
		content = ft_atoi(argv[j]);
		i = 0;
		while (i < stack->stack_a->size)
		{
			if (content == stack->stack_a->stack[i++])
				return (FAIL);
		}
		stack->stack_a->stack[j] = content;
		stack->stack_a->size++;
		j++;
	}
	return (SUCCESS);
}

void	read_stdin(char **result)
{
	char	buffer[2];
	int		size_read;
	char	*tmp;

	size_read = 1;
	*result = NULL;
	while (size_read > 0)
	{
		size_read = read(0, buffer, 1);
		if (size_read < 0)
			return ;
		buffer[size_read] = '\0';
		tmp = ft_strjoin(*result, buffer);
		if (tmp == NULL)
		{
			free(*result);
			return ;
		}
		free(*result);
		*result = tmp;
	}
}

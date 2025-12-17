/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:17:57 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/16 15:45:31 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_bool	parsing_param(t_list **lst, int argc, char **argv)
{
	int		i;
	t_list	*new_node;
	char	*new_string;

	i = 1;
	while (i < argc)
	{
		new_string = ft_strdup(argv[i]);
		if (!new_string)
			return (FAIL);
		new_node = ft_lstnew(new_string);
		if (!new_node)
			return (FAIL);
		ft_lstadd_back(lst, new_node);
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		id;
	int		id1;

	lst = NULL;
	id = fork();
	id1 = fork();
	if (parsing_param(&lst, argc, argv))
		return (FAIL);
	ft_printf("%i, %i, %i\n", ft_lstsize(lst), id, id1);
	return (ft_free_all_malloc(), SUCCESS);
}

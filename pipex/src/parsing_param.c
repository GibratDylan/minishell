/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:58:05 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/22 14:32:36 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static t_bool	is_here_doc(int *i, int argc, char **argv, char **limiter)
{
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		if (2 > argc - 1)
			return (FAIL);
		else
			*limiter = ft_strdup(argv[2]);
		(*i)++;
	}
	return (SUCCESS);
}

t_bool	parsing_param(t_cmd **cmd, int argc, char **argv, char **limiter)
{
	int		i;
	t_cmd	*new_node;
	char	**new_argv;
	char	*new_path;
	char	*tmp;

	i = 2;
	if (is_here_doc(&i, argc, argv, limiter))
		return (FAIL);
	while (i < argc - 1)
	{
		new_argv = ft_split(argv[i], ' ');
		new_path = ft_strjoin("/bin/", new_argv[0], 5);
		tmp = new_argv[0];
		new_argv[0] = ft_strjoin("./", tmp, 2);
		ft_free_malloc(tmp);
		if (!new_argv || !new_path)
			return (FAIL);
		new_node = cmd_new(new_path, new_argv);
		if (!new_node)
			return (FAIL);
		cmd_add_back(cmd, new_node);
		i++;
	}
	return (SUCCESS);
}

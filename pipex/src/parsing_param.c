/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:58:05 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/18 18:02:13 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_bool	parsing_param(t_cmd **cmd, int argc, char **argv)
{
	int		i;
	t_cmd	*new_node;
	char	**new_argv;
	char	*new_path;
	char	*tmp;

	i = 2;
	while (i < argc - 1)
	{
		new_argv = ft_split(argv[i], ' ');
		new_path = ft_strjoin("/usr/bin/", new_argv[0], 9);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:56:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/18 14:57:17 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_cmd	*cmd_new(char *path, char **argv)
{
	t_cmd	*node;

	node = ft_malloc(1, sizeof(t_cmd));
	if (node == NULL)
		return (NULL);
	node->path = path;
	node->argv = argv;
	node->next = NULL;
	return (node);
}

t_cmd	*cmd_last(t_cmd *cmd)
{
	if (cmd == NULL)
		return (cmd);
	while (cmd->next != NULL)
		cmd = cmd->next;
	return (cmd);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new_lst)
{
	t_cmd	*last_node;

	if (*cmd == NULL)
		*cmd = new_lst;
	else
	{
		last_node = cmd_last(*cmd);
		last_node->next = new_lst;
	}
}

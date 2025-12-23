/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:11:42 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/23 15:50:14 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipe(int *fd_pipe, int *fd_pipe_next)
{
	if (fd_pipe)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
	}
	if (fd_pipe_next)
	{
		if (fd_pipe_next[0])
			close(fd_pipe_next[0]);
		if (fd_pipe_next[1])
			close(fd_pipe_next[1]);
	}
}

t_bool	execve_with_dup2(t_cmd *cmd, int from, int to)
{
	if (dup2(from, 0) == -1)
		return (FAIL);
	close(from);
	if (dup2(to, 1) == -1)
		return (FAIL);
	close(to);
	if (execve(cmd->path, cmd->argv, cmd->envp) == -1)
		return (errno);
	return (SUCCESS);
}

t_bool	update_pipe(int *fd_pipe, int *fd_pipe_next)
{
	if (close(fd_pipe[0]) == -1)
		return (close_pipe(fd_pipe, NULL), FAIL);
	fd_pipe[0] = fd_pipe_next[0];
	fd_pipe[1] = fd_pipe_next[1];
	return (SUCCESS);
}

void	status_gestion(int errnum)
{
	if (errnum == 2304)
	{
		ft_free_all_malloc();
		exit(127);
	}
	if (errnum == 256)
	{
		ft_free_all_malloc();
		exit(1);
	}
	return ;
}

void	add_envp_in_cmd(t_cmd *cmd, char **envp)
{
	t_cmd	*head;

	head = cmd;
	while (head)
	{
		head->envp = envp;
		head = head->next;
	}
}

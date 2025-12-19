/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:10:15 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/19 13:11:56 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_bool	infile_handler(char **files, t_cmd **cmd, int *fd_pipe)
{
	pid_t	pid;
	int		fd;
	int		status;

	if (!(*cmd) || !cmd)
		return (FAIL);
	if (pipe(fd_pipe) == -1)
		return (FAIL);
	pid = fork();
	if (pid == -1)
		return (close_pipe(fd_pipe, NULL), FAIL);
	if (pid == 0)
	{
		fd = open(files[0], O_RDONLY);
		if (fd == -1 || close(fd_pipe[0]) == -1)
			return (close_pipe(fd_pipe, NULL), FAIL);
		if (execve_with_dup2(*cmd, fd, fd_pipe[1]))
			return (close_pipe(fd_pipe, NULL), close(fd),
				execve_error_handler((*cmd)->argv[0]), FAIL);
	}
	waitpid(pid, &status, 0);
	if (status)
		return (close_pipe(fd_pipe, NULL), FAIL);
	*cmd = (*cmd)->next;
	return (SUCCESS);
}

t_bool	outfile_handler(char **files, t_cmd **cmd, int *fd_pipe)
{
	pid_t	pid;
	int		fd;
	int		status;

	if (!(*cmd) || !cmd)
		return (close_pipe(fd_pipe, NULL), FAIL);
	if (close(fd_pipe[1]) == -1)
		return (close_pipe(fd_pipe, NULL), FAIL);
	pid = fork();
	if (pid == -1)
		return (close_pipe(fd_pipe, NULL), FAIL);
	if (pid == 0)
	{
		fd = open(files[1], O_WRONLY | O_CREAT | O_TRUNC, 00777);
		if (fd == -1)
			return (close_pipe(fd_pipe, NULL), ft_free_all_malloc(), FAIL);
		if (execve_with_dup2(*cmd, fd_pipe[0], fd))
			return (close_pipe(fd_pipe, NULL),
				execve_error_handler((*cmd)->argv[0]), FAIL);
	}
	waitpid(pid, &status, 0);
	if (status)
		return (close_pipe(fd_pipe, NULL), FAIL);
	return (SUCCESS);
}

t_bool	cmd_handler(t_cmd **cmd, int *fd_pipe, int *fd_pipe_next)
{
	pid_t	pid;
	int		status;

	if (!(*cmd) || !cmd)
		return (close_pipe(fd_pipe, NULL), FAIL);
	while ((*cmd)->next)
	{
		if (close(fd_pipe[1]) == -1 || pipe(fd_pipe_next) == -1)
			return (close_pipe(fd_pipe, NULL), FAIL);
		pid = fork();
		if (pid == -1)
			return (close_pipe(fd_pipe, fd_pipe_next), FAIL);
		if (pid == 0)
		{
			if (close(fd_pipe_next[0]) == -1 || fd_pipe[1] == -1)
				return (close_pipe(fd_pipe, fd_pipe_next), FAIL);
			if (execve_with_dup2(*cmd, fd_pipe[0], fd_pipe_next[1]))
				return (close_pipe(fd_pipe, fd_pipe_next),
					execve_error_handler((*cmd)->argv[0]), FAIL);
		}
		waitpid(pid, &status, 0);
		if (status || close(fd_pipe[0]) == -1 || fd_pipe[1] == -1)
			return (close_pipe(fd_pipe, NULL), FAIL);
		fd_pipe[0] = fd_pipe_next[0];
		fd_pipe[1] = fd_pipe_next[1];
		*cmd = (*cmd)->next;
	}
	return (SUCCESS);
}

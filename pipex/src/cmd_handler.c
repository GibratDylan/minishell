/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:10:15 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/23 15:34:16 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_bool	infile_handler(char **files, t_cmd **cmd, int *fd_pipe)
{
	pid_t	pid;
	int		fd;

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
			return (ft_free_all_malloc(), ft_free_all_malloc(), exit(0),
				SUCCESS);
		if (execve_with_dup2(*cmd, fd, fd_pipe[1]))
			return (close_pipe(fd_pipe, NULL), close(fd), exitfre(cmd), FAIL);
	}
	add_pid_to_wait(pid);
	return (SUCCESS);
}

t_bool	outfile_handler(char **files, t_cmd **cmd, int *fd_pipe, char *limiter)
{
	pid_t	pid;
	int		fd;

	if (!cmd)
		return (close_pipe(fd_pipe, NULL), FAIL);
	if (close(fd_pipe[1]) == -1)
		return (close_pipe(fd_pipe, NULL), FAIL);
	pid = fork();
	if (pid == -1)
		return (close_pipe(fd_pipe, NULL), FAIL);
	if (pid == 0)
	{
		if (!limiter)
			fd = open(files[1], O_WRONLY | O_CREAT | O_TRUNC, 00777);
		else
			fd = open(files[1], O_WRONLY | O_CREAT | O_APPEND, 00777);
		if (fd == -1)
			return (close_pipe(fd_pipe, NULL), FAIL);
		if (execve_with_dup2(*cmd, fd_pipe[0], fd))
			return (close_pipe(fd_pipe, NULL), close(fd), exitfre(cmd), FAIL);
	}
	(add_pid_to_wait(pid), close_pipe(fd_pipe, NULL));
	if (wait_all_pid())
		return (FAIL);
	return (SUCCESS);
}

t_bool	cmd_handler(t_cmd **cmd, int *fd_pipe, int *fd_pipe_next)
{
	pid_t	pid;

	if (!cmd)
		return (close_pipe(fd_pipe, NULL), FAIL);
	*cmd = (*cmd)->next;
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
				return (close_pipe(fd_pipe, fd_pipe_next), exitfre(cmd), FAIL);
		}
		add_pid_to_wait(pid);
		(update_pipe(fd_pipe, fd_pipe_next), *cmd = (*cmd)->next);
	}
	return (SUCCESS);
}

static t_bool	read_in_here_doc(int *fd_pipe_next, char *limiter)
{
	ssize_t	size_read;
	char	buffer[2];
	char	*result;

	size_read = 1;
	result = NULL;
	ft_printf("pipe heredoc> ");
	while (size_read > 0 && !ft_strnstr(result, limiter, ft_strlen(result)))
	{
		size_read = read(0, buffer, 1);
		if (size_read < 0)
			return (FAIL);
		buffer[size_read] = '\0';
		result = ft_strjoin_free(result, buffer, ft_strlen(result));
		if (result == NULL)
			return (FAIL);
		if (buffer[0] == '\n')
			ft_printf("pipe heredoc> ");
	}
	read(0, buffer, 1);
	result = ft_strtrim_free(result, limiter);
	ft_putstr_fd(result, fd_pipe_next[1]);
	close(fd_pipe_next[1]);
	return (SUCCESS);
}

t_bool	limiter_handler(t_cmd **cmd, int *fd_pipe, char *limiter)
{
	pid_t	pid;
	int		fd_pipe_next[2];

	if (!(*cmd) || !cmd)
		return (FAIL);
	if (pipe(fd_pipe) == -1)
		return (FAIL);
	pid = fork();
	if (pid == -1)
		return (close_pipe(fd_pipe, NULL), FAIL);
	if (pid == 0)
	{
		if (pipe(fd_pipe_next) == -1)
			return (FAIL);
		if (read_in_here_doc(fd_pipe_next, limiter))
			return (close_pipe(fd_pipe, fd_pipe_next), FAIL);
		if (execve_with_dup2(*cmd, fd_pipe_next[0], fd_pipe[1]))
			return (close_pipe(fd_pipe, fd_pipe_next), exitfre(cmd), FAIL);
	}
	add_pid_to_wait(pid);
	return (SUCCESS);
}

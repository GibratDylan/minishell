/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:17:57 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/17 20:55:10 by dgibrat          ###   ########.fr       */
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

t_bool	parsing_param(t_cmd **cmd, int argc, char **argv)
{
	int		i;
	t_cmd	*new_node;
	char	**new_argv;
	char	*new_path;
	char	*tmp;

	i = 2;
	while (i < argc)
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

t_bool	check_files(char **argv)
{
	if (access(argv[1], F_OK) == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", argv[1]);
		return (FAIL);
	}
	if (access(argv[1], R_OK) == -1)
		return (ft_printf("zsh: permission denied: %s\n", argv[1]), FAIL);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_cmd	*cmd;
	pid_t	pid;
	int		fd_pipe[2];
	int		fd_pipe1[2];
	int		fd_pipe2[2];
	int		fd;
	char	*line;

	cmd = NULL;
	if (parsing_param(&cmd, argc, argv))
		return (FAIL);
	if (check_files(argv))
		return (ft_free_all_malloc(), SUCCESS);
	if (!cmd)
		return (ft_free_all_malloc(), SUCCESS);
	pipe(fd_pipe);
	pipe(fd_pipe1);
	pid = fork();
	if (pid == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (ft_free_all_malloc(), FAIL);
		dup2(fd, 0);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[0]);
		execve(cmd->path, cmd->argv, cmd->argv);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd_pipe[1]);
		line = get_next_line(fd_pipe[0], 0);
		while (line)
		{
			ft_putstr_fd(line, fd_pipe1[1]);
			line = get_next_line(fd_pipe[0], 0);
		}
		close(fd_pipe[0]);
	}
	pipe(fd_pipe2);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe1[1]);
		dup2(fd_pipe1[0], 0);
		ft_printf("test\n");
		dup2(fd_pipe2[1], 1);
		ft_printf("test\n");
		close(fd_pipe1[0]);
		execve(cmd->next->path, cmd->next->argv, cmd->next->argv);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd_pipe2[1]);
		line = get_next_line(fd_pipe2[0], 0);
		while (line)
		{
			ft_putstr_fd(line, 1);
			line = get_next_line(fd_pipe2[0], 0);
		}
		close(fd_pipe2[0]);
	}
	return (ft_free_all_malloc(), SUCCESS);
}

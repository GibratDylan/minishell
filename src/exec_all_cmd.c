/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_all_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:11:49 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 15:46:42 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	free_redirs(t_redirection **redirs)
{
	int	i;

	if (!redirs)
		return ;
	i = 0;
	while (redirs[i])
	{
		ft_free_malloc(redirs[i]->file);
		ft_free_malloc(redirs[i]);
		i++;
	}
	ft_free_malloc(redirs);
}

static void	free_set_var(t_variable **set_var)
{
	int	i;

	if (!set_var)
		return ;
	i = 0;
	while (set_var[i])
	{
		ft_free_malloc(set_var[i]->key);
		ft_free_malloc(set_var[i]->value);
		ft_free_malloc(set_var[i]);
		i++;
	}
	ft_free_malloc(set_var);
}

t_bool	exec_all_cmd(t_command **cmd)
{
	int		i;
	pid_t	pid;
	int		exit_status;

	i = 0;
	if (!cmd)
		return (SUCCESS);
	while (cmd[i])
	{
		pid = fork();
		if (pid == -1)
			return (perror("fork exec_all_cmd"), FAIL);
		if (!pid)
			exec_cmd(cmd[i]);
		add_pid_to_wait(pid);
		(ft_free_tab((void **)cmd[i]->argv), free_redirs(cmd[i]->redirs),
			free_set_var(cmd[i]->set_var));
		i++;
	}
	wait_all_pid(&exit_status);
	if (cmd[0] && modify_env_value("?", cmd[0]->var, ft_itoa(exit_status)))
		return (FAIL);
	return (SUCCESS);
}

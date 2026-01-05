/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:22:51 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 13:22:12 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test_minishell.h"

t_bool	exec_cmd(t_command *cmd)
{
	(void)cmd;
	execve("/usr/bin/ls", cmd->argv, *(cmd->env));
	ft_free_all_malloc();
	exit(0);
	return (SUCCESS);
}

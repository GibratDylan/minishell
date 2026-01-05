/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:23:31 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 15:46:42 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_list	**get_pid_lst(void)
{
	static t_list	*pid_lst = NULL;

	return (&pid_lst);
}

t_bool	add_pid_to_wait(pid_t pid)
{
	t_list	**pid_lst;
	t_list	*new_node;
	pid_t	*pid_m;

	pid_lst = get_pid_lst();
	pid_m = ft_malloc(1, sizeof(int));
	*pid_m = pid;
	new_node = ft_lstnew(pid_m);
	if (!new_node)
		return (FAIL);
	ft_lstadd_back(pid_lst, new_node);
	return (SUCCESS);
}

t_bool	wait_first_pid(int *exit_status)
{
	t_list	**pid_lst;
	t_list	*tmp;

	pid_lst = get_pid_lst();
	if (!pid_lst || !(*pid_lst))
		return (FAIL);
	if (waitpid(*(pid_t *)((*pid_lst)->content), exit_status, 0) == -1)
	{
		perror("waitpid wait_first_pid");
		return (FAIL);
	}
	tmp = (*pid_lst)->next;
	ft_lstdelone(*pid_lst, ft_free_malloc);
	*pid_lst = tmp;
	return (SUCCESS);
}

t_bool	wait_all_pid(int *exit_status)
{
	t_list	**pid_lst;

	pid_lst = get_pid_lst();
	while (*pid_lst)
	{
		if (wait_first_pid(exit_status))
			return (FAIL);
		pid_lst = get_pid_lst();
	}
	return (SUCCESS);
}

t_bool	send_signal_all_pid(int signal)
{
	t_list	**pid_lst;
	t_list	*node;

	pid_lst = get_pid_lst();
	node = *pid_lst;
	while (node)
	{
		if (kill(*(pid_t *)((*pid_lst)->content), signal) == -1)
		{
			perror("kill send_signal_all_pid");
			return (FAIL);
		}
		node = node->next;
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:23:31 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/23 15:37:39 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

t_bool	wait_first_pid(int *status)
{
	t_list	**pid_lst;
	t_list	*tmp;

	pid_lst = get_pid_lst();
	if (!pid_lst || !(*pid_lst))
		return (FAIL);
	waitpid(*(pid_t *)((*pid_lst)->content), status, 0);
	tmp = (*pid_lst)->next;
	ft_lstdelone(*pid_lst, ft_free_malloc);
	*pid_lst = tmp;
	return (SUCCESS);
}

t_bool	wait_all_pid(void)
{
	t_list	**pid_lst;
	int		status;

	status = 0;
	pid_lst = get_pid_lst();
	while (*pid_lst)
	{
		if (wait_first_pid(&status))
			return (FAIL);
		pid_lst = get_pid_lst();
	}
	if (status)
		status_gestion(status);
	return (SUCCESS);
}

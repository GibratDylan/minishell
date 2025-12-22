/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:05 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/22 15:04:15 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_bool	check_files(char **argv, int argc, char **files, char *limiter)
{
	if (!limiter)
	{
		if (access(argv[1], F_OK) == -1)
			ft_printf("zsh: no such file or directory: %s\n", argv[1]);
		if (access(argv[1], R_OK) == -1)
			ft_printf("zsh: permission denied: %s\n", argv[1]);
		files[0] = ft_strdup(argv[1]);
	}
	if (!access(argv[argc - 1], F_OK) && access(argv[argc - 1], W_OK) == -1)
		return (ft_printf("zsh: permission denied: %s\n", argv[argc - 1]),
			FAIL);
	files[1] = ft_strdup(argv[argc - 1]);
	return (SUCCESS);
}

void	execve_error_handler(char *path)
{
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putendl_fd(path, 2);
}

void	exitfre(t_cmd **cmd)
{
	execve_error_handler(&(*cmd)->argv[0][2]);
	ft_free_all_malloc();
	exit(errno);
}

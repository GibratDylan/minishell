/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:48:40 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 09:14:25 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test_minishell.h"

t_bool	check_acces(char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(path, 2);
		return (FAIL);
	}
	else if (access(path, R_OK) == -1)
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(path, 2);
		return (FAIL);
	}
	return (SUCCESS);
}

t_bool	cmd_cd(int argc, char **argv, char **env)
{
	char	*path;

	(void)argv;
	if (argc == 1)
		path = ft_getenv("HOME", env);
	else
		path = argv[1];
	if (!path)
		return (SUCCESS);
	if (check_acces(path))
		return (FAIL); // set_exit_status(1);
	if (chdir(path) == -1)
	{
		perror("chdir cmd_cd");
		return (FAIL);
	}
	return (SUCCESS);
}

// int	main(int argc, char **argv, char **env)
// {
// 	cmd_cd(argc, argv, env);
// 	return (SUCCESS);
// }

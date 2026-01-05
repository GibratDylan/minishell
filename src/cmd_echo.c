/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:48:14 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 15:46:40 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_bool	cmd_echo(char **argv)
{
	t_bool	add_new_line;
	int		i;

	i = 1;
	add_new_line = 1;
	if (!ft_strncmp(argv[1], "-n", 2))
	{
		add_new_line = 0;
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (add_new_line)
		printf("\n");
	return (SUCCESS);
}

// int	main(int argc, char **argv, char **env)
// {
//	(void)argc;
//	(void)env;
// 	cmd_echo(argv);
// 	return (SUCCESS);
// }

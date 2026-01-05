/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:14:32 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 14:30:48 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test_minishell.h"

static t_command	**create_array_test(void)
{
	t_command	**cmd;

	cmd = ft_malloc(2, sizeof(t_command *));
	cmd[0] = ft_malloc(1, sizeof(t_command));
	cmd[0]->argc = 1;
	cmd[0]->redirs = NULL;
	cmd[0]->set_var = NULL;
	cmd[0]->sep = NONE;
	cmd[1] = NULL;
	return (cmd);
}

int	main(int argc, char **argv, char **env)
{
	t_command	**cmd;
	char		**env_cpy;
	char		**var_cpy;

	cmd = create_array_test();
	cmd[0]->argc = argc - 1;
	cmd[0]->argv = ft_cpy_tab(&argv[1]);
	env_cpy = ft_cpy_tab(env);
	var_cpy = ft_cpy_tab(env);
	cmd[0]->env = &env_cpy;
	cmd[0]->var = &var_cpy;
	// exec_all_cmd(cmd);
	printf("%s\n", *(cmd[0]->env)[1]);
	add_env_line("?", cmd[0]->env, "0");
	printf("%s\n", *(cmd[0]->env)[ft_tab_len(*(cmd[0]->env)) - 2]);
	printf("%i\n", ft_tab_len(*(cmd[0]->env)));
	ft_free_all_malloc();
	return (SUCCESS);
}

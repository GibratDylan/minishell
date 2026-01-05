/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:48:47 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 13:43:38 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef minishell_H
# define minishell_H

# include "../libft/include/libft.h"
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <sys/wait.h>

typedef enum e_redirection_type
{
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}							t_e_redirection_type;

typedef enum e_separator
{
	NONE,
	SEP_PIPE,
	SEP_AND,
	SEP_OR
}							t_e_separator;

typedef struct s_redirection
{
	t_e_redirection_type	type;
	char					*file;
}							t_redirection;

typedef struct s_variable
{
	char					*key;
	char					*value;
}							t_variable;

typedef struct s_command
{
	int						argc;
	char					**argv;
	t_redirection			**redirs;
	char					***env;
	char					***var;
	t_variable				**set_var;
	t_e_separator			sep;
}							t_command;

char						*get_env_value(const char *name, char **env);
int							get_env_line(const char *name, char **env);
t_bool						send_signal_all_pid(int signal);
t_bool						wait_all_pid(int *status);
t_bool						wait_first_pid(int *status);
t_bool						add_pid_to_wait(pid_t pid);
t_bool						exec_all_cmd(t_command **cmd);
t_bool						exec_cmd(t_command *cmd);
t_bool						modify_env_value(const char *name, char ***env,
								char *new_value);
t_bool						add_env_line(const char *name, char ***env,
								char *new_value);

#endif
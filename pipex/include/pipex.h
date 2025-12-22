/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:18:09 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/22 15:04:12 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char			*path;
	char			**argv;
	struct s_cmd	*next;
	char			**envp;
}					t_cmd;

t_cmd				*cmd_new(char *path, char **argv);
t_cmd				*cmd_last(t_cmd *cmd);
void				cmd_add_back(t_cmd **cmd, t_cmd *new_lst);
t_bool				parsing_param(t_cmd **cmd, int argc, char **argv,
						char **limiter);
t_bool				check_files(char **argv, int argc, char **files,
						char *limiter);
void				execve_error_handler(char *path);
t_bool				infile_handler(char **files, t_cmd **cmd, int *fd_pipe);
t_bool				cmd_handler(t_cmd **cmd, int *fd_pipe, int *fd_pipe_next);
void				close_pipe(int *fd_pipe, int *fd_pipe_next);
t_bool				outfile_handler(char **files, t_cmd **cmd, int *fd_pipe,
						char *limiter);
t_bool				limiter_handler(t_cmd **cmd, int *fd_pipe, char *limiter);
t_bool				execve_with_dup2(t_cmd *cmd, int from, int to);
t_bool				update_pipe(int *fd_pipe, int *fd_pipe_next);
void				status_gestion(int errnum);
void				add_envp_in_cmd(t_cmd *cmd, char **envp);
void				exitfre(t_cmd **cmd);

#endif
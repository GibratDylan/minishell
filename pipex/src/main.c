/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:17:57 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/20 16:50:44 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	t_cmd	*cmd;
	char	*files[2];
	int		fd_pipe[2];
	int		fd_pipe_next[2];
	char	*limiter;

	cmd = NULL;
	limiter = NULL;
	if (parsing_param(&cmd, argc, argv, &limiter))
		return (ft_free_all_malloc(), FAIL);
	if (check_files(argv, argc, files, limiter))
		return (ft_free_all_malloc(), FAIL);
	if (!limiter && infile_handler(files, &cmd, fd_pipe))
		return (ft_free_all_malloc(), FAIL);
	if (limiter && limiter_handler(&cmd, fd_pipe, limiter))
		return (ft_free_all_malloc(), FAIL);
	if (cmd && cmd->next && cmd_handler(&cmd, fd_pipe, fd_pipe_next))
		return (ft_free_all_malloc(), FAIL);
	if (cmd && outfile_handler(files, &cmd, fd_pipe, limiter))
		return (ft_free_all_malloc(), FAIL);
	return (close_pipe(fd_pipe, NULL), ft_free_all_malloc(), SUCCESS);
}

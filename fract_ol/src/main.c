/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:04:40 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 16:48:28 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "fcntl.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/home/dgibrat/Project/Home/fract_ol/minilibx-linux/man/man1/mlx_loop.1",
			O_RDONLY);
	while ((line = get_next_line(fd)))
		ft_printf("%s", line);
}

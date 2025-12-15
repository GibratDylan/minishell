/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:24:50 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/15 15:43:27 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	create_trgb(short t, short r, short g, short b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_coord	*set_coordinate(t_coord *coord)
{
	coord->min_x = MIN_X;
	coord->max_x = MAX_X;
	coord->min_y = MIN_Y;
	coord->max_y = MAX_X;
	return (coord);
}

void	close_and_free(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	ft_free_all_malloc();
}

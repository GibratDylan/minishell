/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:03:44 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/15 15:46:05 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	go_up(t_data *img)
{
	double	range;

	range = (img->coord->max_y - img->coord->min_y) / (double)SCRREN_HEIGHT;
	img->coord->min_y = img->coord->min_y - (range * 100);
	img->coord->max_y = img->coord->max_y - (range * 100);
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	go_down(t_data *img)
{
	double	range;

	range = (img->coord->max_y - img->coord->min_y) / (double)SCRREN_HEIGHT;
	img->coord->min_y = img->coord->min_y + (range * 100);
	img->coord->max_y = img->coord->max_y + (range * 100);
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	go_left(t_data *img)
{
	double	range;

	range = (img->coord->max_x - img->coord->min_x) / (double)SCREEN_WIDTH;
	img->coord->min_x = img->coord->min_x - (range * 100);
	img->coord->max_x = img->coord->max_x - (range * 100);
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	go_right(t_data *img)
{
	double	range;

	range = (img->coord->max_x - img->coord->min_x) / (double)SCREEN_WIDTH;
	img->coord->min_x = img->coord->min_x + (range * 100);
	img->coord->max_x = img->coord->max_x + (range * 100);
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	go_exit(t_data *img)
{
	close_and_free(img);
	exit(0);
}

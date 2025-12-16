/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:17:20 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/16 09:35:52 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_hook(int button, int x, int y, t_data *img)
{
	double			mx;
	double			my;
	double			zoom_factor;
	static short	number_of_zoom = 0;

	if (button != 4 && button != 5)
		return (0);
	mx = normalization(img->coord->min_x, img->coord->max_x, SCREEN_WIDTH, x);
	my = normalization(img->coord->min_y, img->coord->max_y, SCRREN_HEIGHT, y);
	zoom_factor = 1;
	if (button == 4 && number_of_zoom < 175 && number_of_zoom++)
		zoom_factor = 0.85;
	else if (button == 5 && number_of_zoom > -15 && number_of_zoom--)
		zoom_factor = 1.25;
	img->coord->min_x = mx + (img->coord->min_x - mx) * zoom_factor;
	img->coord->max_x = mx + (img->coord->max_x - mx) * zoom_factor;
	img->coord->min_y = my + (img->coord->min_y - my) * zoom_factor;
	img->coord->max_y = my + (img->coord->max_y - my) * zoom_factor;
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	key_hook(int button, t_data *img)
{
	if (button == UP_ARROW)
		go_up(img);
	if (button == DOWN_ARROW)
		go_down(img);
	if (button == LEFT_ARROW)
		go_left(img);
	if (button == RIGHT_ARROW)
		go_right(img);
	if (button == ESC_KEY)
		go_exit(img);
	return (0);
}

int	cross_exit(t_data *img)
{
	go_exit(img);
	return (0);
}

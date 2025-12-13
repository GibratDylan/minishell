/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:17:20 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 20:52:30 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	mouse_hook(int button, int x, int y, t_data *img)
{
	double	mx;
	double	my;
	double	zoom_factor;

	mx = normalization(img->min_x, img->max_x, SCREEN_WIDTH, x);
	my = normalization(img->min_y, img->max_y, SCRREN_HEIGHT, y);
	if (button != 4 && button != 5)
		return (0);
	{
		if (button == 4)
			zoom_factor = 0.85;
		else
			zoom_factor = 1.3;
		img->min_x = mx + (img->min_x - mx) * zoom_factor;
		img->max_x = mx + (img->max_x - mx) * zoom_factor;
		img->min_y = my + (img->min_y - my) * zoom_factor;
		img->max_y = my + (img->max_y - my) * zoom_factor;
	}
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:11:07 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 20:58:15 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	my_mlx_pixel_put(t_data *data, short x, short y, short color)
{
	char	*dst1;

	dst1 = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst1 = color;
}

#include <stdio.h>

void	launch_rendering(t_data *img)
{
	double	real;
	double	imag;
	double	range_real;
	double	range_imag;
	short	screen_y;
	short	screen_x;

	range_real = (((img->max_x - img->min_x) / (double)SCREEN_WIDTH));
	range_imag = (img->max_y - img->min_y) / (double)SCRREN_HEIGHT;
	real = img->min_x;
	imag = img->min_y;
	screen_y = 0;
	while (screen_y < SCRREN_HEIGHT)
	{
		screen_x = 0;
		while (screen_x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(img, screen_x, screen_y, calculation_complex(real,
					imag, ITERATION, img));
			real += range_real;
			screen_x += 1;
		}
		real = img->min_x;
		imag += range_imag;
		screen_y += 1;
	}
}

static int	*set_palette(t_param *param)
{
	int	*result;
	int	i;

	(void)param;
	result = ft_malloc((ITERATION), sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	while (i <= ITERATION)
	{
		if (i < ITERATION / 3)
			result[i] = create_trgb(0, 0, 0, ((i * 255) / (ITERATION / 3)));
		if (i < (ITERATION / 3) * 2)
			result[i] = create_trgb(0, ((i * 255) / ((ITERATION / 3) * 2)), ((i
							* 255) / ((ITERATION / 3) * 2)), 255);
		else
			result[i] = create_trgb(0, 0, ((i * 255) / ITERATION), 255);
		i++;
	}
	return (result);
}

t_bool	rendering(t_param *param)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, SCREEN_WIDTH, SCRREN_HEIGHT,
			"fract-ol");
	img.img = mlx_new_image(img.mlx, SCREEN_WIDTH, SCRREN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.palette = set_palette(param);
	if (!img.palette)
		return (FAIL);
	img.param = param;
	set_coordinate(&img);
	launch_rendering(&img);
	mlx_mouse_hook(img.mlx_win, mouse_hook, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (SUCCESS);
}

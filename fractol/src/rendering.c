/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:11:07 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/17 12:36:43 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	my_mlx_pixel_put(t_data *img, short x, short y, short color)
{
	char	*dst1;

	dst1 = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst1 = color;
}

static void	put_all_pixel(t_data *img, double range_real, double range_imag)
{
	short	screen_y;
	short	screen_x;
	double	real;
	double	imag;

	real = img->coord->min_x;
	imag = img->coord->min_y;
	screen_y = 0;
	while (screen_y < SCRREN_HEIGHT)
	{
		screen_x = 0;
		while (screen_x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(img, screen_x, screen_y, calculation_complex(real,
					imag, ITERATION, img));
			real += range_real;
			screen_x++;
		}
		real = img->coord->min_x;
		imag += range_imag;
		screen_y++;
	}
}

void	launch_rendering(t_data *img)
{
	double	range_real;
	double	range_imag;

	range_real = (img->coord->max_x - img->coord->min_x) / (double)SCREEN_WIDTH;
	range_imag = (img->coord->max_y - img->coord->min_y)
		/ (double)SCRREN_HEIGHT;
	put_all_pixel(img, range_real, range_imag);
}

static int	*set_palette(t_param *param)
{
	int	*palette;

	palette = ft_malloc((ITERATION + 1), sizeof(int));
	if (!palette)
		return (NULL);
	if (param->color == COLOR_WHITE)
		color_white(palette);
	if (param->color == COLOR_BLUE)
		color_blue(palette);
	if (param->color == COLOR_PSYC)
		color_psyc(palette);
	return (palette);
}

t_bool	rendering(t_data *img, t_param *param)
{
	t_coord	coord;

	img->mlx = mlx_init();
	if (!img->mlx)
		return (FAIL);
	img->win = mlx_new_window(img->mlx, SCREEN_WIDTH, SCRREN_HEIGHT, "fractol");
	img->img = mlx_new_image(img->mlx, SCREEN_WIDTH, SCRREN_HEIGHT);
	img->palette = set_palette(param);
	if (!img->img || !img->win || !img->palette)
		return (FAIL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->param = param;
	img->coord = set_coordinate(&coord);
	if (img->param->shift)
		mlx_loop_hook(img->mlx, shift_color, img);
	mlx_mouse_hook(img->win, mouse_hook, img);
	mlx_key_hook(img->win, key_hook, img);
	mlx_hook(img->win, 17, 17, cross_exit, img);
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
	return (SUCCESS);
}

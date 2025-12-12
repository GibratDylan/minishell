/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:04:40 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/12 15:58:52 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "stdio.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	normalization(double min_to, double max_to, double max_from,
		double value)
{
	return (((max_to - min_to) / max_from) * value + (max_to - ((max_to
					- min_to) / max_from) * max_from));
}

int	ft_abs(int value)
{
	if (value >= 0)
		return (value);
	else
		return (value * -1);
}

int	calculation_complex(double real, double imag, int iteration)
{
	double	result_real;
	double	result_imag;
	double	normalized;

	result_real = (real * real) - (imag * imag);
	result_imag = (real * imag) + (imag * real);
	real = result_real;
	imag = result_imag;
	real += 0.3;
	imag += 0.5;
	while (iteration)
	{
		result_real = (real * real) - (imag * imag);
		result_imag = (real * imag) + (imag * real);
		real = result_real;
		imag = result_imag;
		real += 0.3;
		imag += 0.5;
		if (ft_abs(real) > 2 || ft_abs(imag) > 2)
		{
			normalized = normalization(0, 200, 50, iteration);
			return (create_trgb(0, 0, 0, normalized));
		}
		iteration--;
	}
	return (0x00000000);
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	double			px;
	double			py;
	double			real;
	double			imag;
	static double	min = -1.5;
	static double	max = 1.5;

	(void)x;
	(void)y;
	if (button == 4)
	{
		min *= 0.9;
		max *= 0.9;
		// min += normalization(min, 0, 960, x) + normalization(min, 0, 640, y);
		// max += normalization(0, max, 640, y) + normalization(0, max, 960, x);
	}
	else if (button == 5)
	{
		min *= 1.1;
		max *= 1.1;
		// min += normalization(min, max, 960, x) + normalization(min, max, 640,
		// 		y);
		// max += normalization(min, max, 640, y) + normalization(min, max, 960,
		// 		x);
	}
	else
		return (0);
	py = 0;
	while (py < 640)
	{
		px = 0;
		while (px < 960)
		{
			real = normalization(min, max, 960, px);
			imag = normalization(min, max, 640, py);
			my_mlx_pixel_put(img, (int)px, (int)py, calculation_complex(real,
					imag, 100));
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	*img;
	double	x;
	double	y;
	double	real;
	double	imag;

	img = malloc(sizeof(t_data));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 960, 640, "Hello world!");
	img->img = mlx_new_image(img->mlx, 960, 640);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	y = 0;
	while (y < 640)
	{
		x = 0;
		while (x < 960)
		{
			real = normalization(-1.5, 1.5, 960, x);
			imag = normalization(-1.5, 1.5, 640, y);
			my_mlx_pixel_put(img, x++, y, calculation_complex(real, imag, 100));
		}
		y++;
	}
	mlx_mouse_hook(img->mlx_win, mouse_hook, img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(img->mlx);
}

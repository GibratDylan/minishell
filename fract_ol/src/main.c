/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:04:40 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/11 20:22:01 by dgibrat          ###   ########.fr       */
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

t_complex	multiplication_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = (a.real * b.real) - (a.imag * b.imag);
	result.imag = (a.real * b.imag) + (a.imag * b.real);
	return (result);
}

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

int	calculation_complex(t_complex a, int iteration)
{
	t_complex	result;
	double		normalized;

	result = multiplication_complex(a, a);
	result.real += 0.3;
	result.imag += 0.5;
	while (iteration)
	{
		result = multiplication_complex(result, result);
		result.real += 0.3;
		result.imag += 0.5;
		if (result.real > 4 || result.imag > 4)
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
	t_complex		a;
	static double	min = 0;
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
			a.real = normalization(min, max, 960, px);
			a.imag = normalization(min, max, 640, py);
			my_mlx_pixel_put(img, (int)px, (int)py, calculation_complex(a, 50));
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data		*img;
	double		x;
	double		y;
	t_complex	a;

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
			a.real = normalization(0, 1.5, 960, x);
			a.imag = normalization(0, 1.5, 640, y);
			my_mlx_pixel_put(img, x++, y, calculation_complex(a, 50));
		}
		y++;
	}
	mlx_mouse_hook(img->mlx_win, mouse_hook, img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(img->mlx);
}

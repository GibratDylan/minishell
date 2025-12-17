/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:21:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/17 12:35:40 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_white(int *palette)
{
	int	i;

	i = 0;
	while (i <= ITERATION)
	{
		if (i < ITERATION / 3)
			palette[i] = create_trgb(0, 0, 0, ((i * 255) / (ITERATION / 3)));
		if (i < (ITERATION / 3) * 2)
			palette[i] = create_trgb(0, ((i * 255) / ((ITERATION / 3) * 2)), ((i
							* 255) / ((ITERATION / 3) * 2)), 255);
		else
			palette[i] = create_trgb(0, 0, ((i * 255) / ITERATION), 255);
		i++;
	}
}

void	color_blue(int *palette)
{
	int	i;

	i = 0;
	while (i <= ITERATION)
	{
		palette[i] = i * (0x00FFFFFF / ITERATION) / 60;
		i++;
	}
}

void	color_psyc(int *palette)
{
	int	i;

	i = 0;
	while (i <= ITERATION)
	{
		palette[i] = (0x00FFFFFF * i) / ITERATION;
		i++;
	}
}

int	shift_color(t_data *img)
{
	int	i;

	i = 0;
	while (i <= ITERATION)
	{
		img->palette[i % ITERATION] = img->palette[(i + 1) % ITERATION];
		i++;
	}
	launch_rendering(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

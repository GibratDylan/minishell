/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:25:53 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/15 15:56:32 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	normalization(double min_to, double max_to, double max_from,
		short value)
{
	double	max_minus_min;
	double	max_minus_min_div_max_from;

	max_minus_min = max_to - min_to;
	max_minus_min_div_max_from = max_minus_min / max_from;
	return (max_minus_min_div_max_from * value + (max_to
			- max_minus_min_div_max_from * max_from));
}

static int	julia_calculation(double real, double imag, short iteration,
		t_data *img)
{
	double	real_multi;
	double	imag_multi;
	double	param_real;
	double	param_imag;

	param_real = img->param->real;
	param_imag = img->param->imag;
	while (iteration)
	{
		real_multi = real * real;
		imag_multi = imag * imag;
		imag = 2 * real * imag + param_imag;
		real = real_multi - imag_multi + param_real;
		if (real_multi + imag_multi > 4.0)
			return (img->palette[iteration]);
		iteration--;
	}
	return (0x00000000);
}

static int	mandel_calculation(double real, double imag, short iteration,
		t_data *img)
{
	double	real_multi;
	double	imag_multi;
	double	param_real;
	double	param_imag;

	param_real = real;
	param_imag = imag;
	real = 0;
	imag = 0;
	while (iteration)
	{
		real_multi = real * real;
		imag_multi = imag * imag;
		imag = 2 * real * imag + param_imag;
		real = real_multi - imag_multi + param_real;
		if (real_multi + imag_multi > 4.0)
			return (img->palette[iteration]);
		iteration--;
	}
	return (0x00000000);
}

static int	ship_calculation(double real, double imag, short iteration,
		t_data *img)
{
	double	real_multi;
	double	imag_multi;
	double	param_real;
	double	param_imag;

	param_real = real;
	param_imag = imag;
	real = 0;
	imag = 0;
	while (iteration)
	{
		real_multi = real * real;
		imag_multi = imag * imag;
		imag = ft_abs(2 * real * imag) + param_imag;
		real = real_multi - imag_multi + param_real;
		if (real_multi + imag_multi > 4.0)
			return (img->palette[iteration]);
		iteration--;
	}
	return (0x00000000);
}

int	calculation_complex(double real, double imag, short iteration, t_data *img)
{
	if (img->param->set == SET_JULIA)
		return (julia_calculation(real, imag, iteration, img));
	else if (img->param->set == SET_MANDEL)
		return (mandel_calculation(real, imag, iteration, img));
	else if (img->param->set == SET_SHIP)
		return (ship_calculation(real, imag, iteration, img));
	return (0x00000000);
}

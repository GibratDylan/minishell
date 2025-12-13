/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:25:53 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 20:48:42 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

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

int	calculation_complex(double real, double imag, short iteration, t_data *img)
{
	double	result_real;
	double	result_imag;
	double	real_imag_multi;
	double	rad_sq;
	double	prev_real;
	double	prev_imag;

	prev_real = 0;
	prev_imag = 0;
	while (iteration)
	{
		real_imag_multi = real * imag;
		result_real = (real * real) - (imag * imag);
		result_imag = real_imag_multi + real_imag_multi;
		real = result_real + img->param->real;
		imag = result_imag + img->param->imag;
		if (prev_real == real && prev_imag == imag)
			return (0x00000000);
		if (iteration % 2)
		{
			prev_real = real;
			prev_imag = imag;
		}
		rad_sq = real * real + imag * imag;
		if (rad_sq > 4.0)
			return (img->palette[iteration]);
		iteration--;
	}
	return (0x00000000);
}

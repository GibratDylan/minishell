/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:24:50 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 20:58:00 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	create_trgb(short t, short r, short g, short b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_coordinate(t_data *img)
{
	img->min_x = MIN_X;
	img->max_x = MAX_X;
	img->min_y = MIN_Y;
	img->max_y = MAX_X;
}

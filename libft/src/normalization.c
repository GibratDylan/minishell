/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:09:56 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/20 17:10:14 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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

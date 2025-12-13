/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:22:50 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 20:09:18 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

t_bool	is_valid_param(int argc, char **argv)
{
	if (argc == 1)
		return (FAIL);
	if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) && ft_strncmp(argv[1],
			"Mandelbrot", ft_strlen(argv[1])))
		return (FAIL);
	argc -= 2;
	if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
	{
		if (argc-- == 0 || !ft_isnumber(argv[2]) || argc-- == 0
			|| !ft_isnumber(argv[3]))
			return (FAIL);
	}
	if ((argc != 0 && ft_strncmp(argv[2], "Cyan", ft_strlen(argv[2]))
			&& ft_strncmp(argv[2], "Red", ft_strlen(argv[2]))
			&& ft_strncmp(argv[2], "Psyc", ft_strlen(argv[2])))
		&& !ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])))
		return (FAIL);
	if ((argc != 0 && ft_strncmp(argv[4], "Cyan", ft_strlen(argv[4]))
			&& ft_strncmp(argv[4], "Red", ft_strlen(argv[4]))
			&& ft_strncmp(argv[4], "Psyc", ft_strlen(argv[4])))
		&& !ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
		return (FAIL);
	if (argc > 1)
		return (FAIL);
	return (SUCCESS);
}

void	show_valid_param(void)
{
	ft_printf("<Set> <real if Set is Julia> <imag if Set is Julia> <Color>\n"\
				"Set: Julia / Mandelbrot\n"\
				"Color: Cyan / Red / Psyc\n");
}

static void	get_color(t_param *param, char **argv)
{
	if (param->set == SET_JULIA && !ft_strncmp(argv[4], "Cyan",
			ft_strlen(argv[4])))
		param->color = COLOR_CYAN;
	else if (param->set == SET_JULIA && !ft_strncmp(argv[4], "Red",
			ft_strlen(argv[4])))
		param->color = COLOR_RED;
	else if (param->set == SET_JULIA && !ft_strncmp(argv[4], "Psyc",
			ft_strlen(argv[4])))
		param->color = COLOR_PSYC;
	else if (param->set == SET_MANDEL && !ft_strncmp(argv[2], "Cyan",
			ft_strlen(argv[2])))
		param->color = COLOR_CYAN;
	else if (param->set == SET_MANDEL && !ft_strncmp(argv[2], "Red",
			ft_strlen(argv[2])))
		param->color = COLOR_RED;
	else if (param->set == SET_MANDEL && !ft_strncmp(argv[2], "Psyc",
			ft_strlen(argv[2])))
		param->color = COLOR_PSYC;
}

void	get_param(t_param *param, char **argv)
{
	if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
		param->set = SET_JULIA;
	else if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])))
		param->set = SET_MANDEL;
	if (param->set == SET_JULIA)
	{
		param->real = ft_atof(argv[2]);
		param->imag = ft_atof(argv[3]);
	}
	else if (param->set == SET_MANDEL)
	{
		param->real = 0;
		param->imag = 0;
	}
	get_color(param, argv);
}

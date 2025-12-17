/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:22:50 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/17 12:12:18 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_bool	is_valid_color(int argc_count, char **argv)
{
	if ((argc_count != 0 && ft_strncmp(argv[2], "White", ft_strlen(argv[2]))
			&& ft_strncmp(argv[2], "Blue", ft_strlen(argv[2]))
			&& ft_strncmp(argv[2], "Psyc", ft_strlen(argv[2])))
		&& (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1]))))
		return (FAIL);
	if ((argc_count != 0 && ft_strncmp(argv[2], "White", ft_strlen(argv[2]))
			&& ft_strncmp(argv[2], "Blue", ft_strlen(argv[2]))
			&& ft_strncmp(argv[2], "Psyc", ft_strlen(argv[2])))
		&& !ft_strncmp(argv[1], "Burning", ft_strlen(argv[1])))
		return (FAIL);
	if ((argc_count != 0 && ft_strncmp(argv[4], "White", ft_strlen(argv[4]))
			&& ft_strncmp(argv[4], "Blue", ft_strlen(argv[4]))
			&& ft_strncmp(argv[4], "Psyc", ft_strlen(argv[4])))
		&& !ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
		return (FAIL);
	return (SUCCESS);
}

t_bool	is_valid_param(int argc, char **argv, t_param *param)
{
	int	argc_count;

	argc_count = argc;
	if (argc_count == 1)
		return (FAIL);
	if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) && ft_strncmp(argv[1],
			"Mandelbrot", ft_strlen(argv[1])) && ft_strncmp(argv[1], "Burning",
			ft_strlen(argv[1])))
		return (FAIL);
	argc_count -= 2;
	if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
	{
		if (argc_count-- == 0 || !ft_isnumber(argv[2]) || argc_count-- == 0
			|| !ft_isnumber(argv[3]))
			return (FAIL);
	}
	if (is_valid_color(argc_count, argv))
		return (FAIL);
	if (argc_count > 1
		&& ft_strncmp(argv[argc - 1], "Shift", ft_strlen(argv[argc - 1])))
		return (FAIL);
	else if (argc_count > 1
		&& !ft_strncmp(argv[argc - 1], "Shift", ft_strlen(argv[argc - 1])))
		param->shift = 1;
	return (SUCCESS);
}

void	show_valid_param(void)
{
	ft_printf(\
"<Set> <real if Set is Julia> <imag if Set is Julia> <Color> <Shift if Color>\n"\
"Set: Julia / Mandelbrot / Burning (real) (imag)\n"\
"Color: White / Blue / Psyc (Shift)\n");
}

static void	get_color(t_param *param, char **argv)
{
	if (param->set == SET_JULIA && !ft_strncmp(argv[4], "White",
			ft_strlen(argv[4])))
		param->color = COLOR_WHITE;
	else if (param->set == SET_JULIA && !ft_strncmp(argv[4], "Blue",
			ft_strlen(argv[4])))
		param->color = COLOR_BLUE;
	else if (param->set == SET_JULIA && !ft_strncmp(argv[4], "Psyc",
			ft_strlen(argv[4])))
		param->color = COLOR_PSYC;
	else if ((param->set == SET_MANDEL || param->set == SET_SHIP)
		&& !ft_strncmp(argv[2], "White", ft_strlen(argv[2])))
		param->color = COLOR_WHITE;
	else if ((param->set == SET_MANDEL || param->set == SET_SHIP)
		&& !ft_strncmp(argv[2], "Blue", ft_strlen(argv[2])))
		param->color = COLOR_BLUE;
	else if ((param->set == SET_MANDEL || param->set == SET_SHIP)
		&& !ft_strncmp(argv[2], "Psyc", ft_strlen(argv[2])))
		param->color = COLOR_PSYC;
}

void	get_param(t_param *param, char **argv)
{
	if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
		param->set = SET_JULIA;
	else if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])))
		param->set = SET_MANDEL;
	else if (!ft_strncmp(argv[1], "Burning", ft_strlen(argv[1])))
		param->set = SET_SHIP;
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
	else if (param->set == SET_SHIP)
	{
		param->real = 0;
		param->imag = 0;
	}
	get_color(param, argv);
}

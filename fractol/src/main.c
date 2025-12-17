/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:15:36 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/17 12:31:53 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_param	param;
	t_data	img;

	param.color = 0;
	param.shift = 0;
	if (is_valid_param(argc, argv, &param))
		return (show_valid_param(), SUCCESS);
	get_param(&param, argv);
	if (rendering(&img, &param))
		return (close_and_free(&img), SUCCESS);
	return (close_and_free(&img), SUCCESS);
}

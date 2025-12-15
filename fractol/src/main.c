/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:15:36 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/15 13:53:38 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_param	param;
	t_data	img;

	if (is_valid_param(argc, argv))
		return (show_valid_param(), SUCCESS);
	get_param(&param, argv);
	if (rendering(&img, &param))
		return (close_and_free(&img), SUCCESS);
	return (close_and_free(&img), SUCCESS);
}

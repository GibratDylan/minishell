/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:05:23 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 20:48:39 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <sys/time.h>

# define SCREEN_WIDTH 1280
# define SCRREN_HEIGHT 720
# define ITERATION 125
# define MIN_X -1.5
# define MAX_X 1.5
# define MIN_Y -0.84
# define MAX_Y 0.84
# define SET_JULIA 0
# define SET_MANDEL 1
# define COLOR_CYAN 0
# define COLOR_RED 1
# define COLOR_PSYC 2

typedef struct s_param
{
	short	set;
	double	real;
	double	imag;
	short	color;
}			t_param;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*palette;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	t_param	*param;
}			t_data;

void		show_valid_param(void);
t_bool		is_valid_param(int argc, char **argv);
void		get_param(t_param *param, char **argv);
t_bool		rendering(t_param *param);
int			create_trgb(short t, short r, short g, short b);
void		launch_rendering(t_data *img);
void		set_coordinate(t_data *img);
int			calculation_complex(double real, double imag, short iteration,
				t_data *img);
int			mouse_hook(int button, int x, int y, t_data *img);
double		normalization(double min_to, double max_to, double max_from,
				short value);
void		my_mlx_pixel_put(t_data *data, short x, short y, short color);

#endif
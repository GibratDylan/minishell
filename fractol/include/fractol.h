/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:05:23 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/15 16:50:17 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

# define SCREEN_WIDTH 1280
# define SCRREN_HEIGHT 720
# define ITERATION 100
# define MIN_X -1.5
# define MAX_X 1.5
# define MIN_Y -0.84
# define MAX_Y 0.84
# define SET_JULIA 0
# define SET_MANDEL 1
# define SET_SHIP 2
# define COLOR_WHITE 0
# define COLOR_BLUE 1
# define COLOR_PSYC 2
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC_KEY 65307

typedef struct s_param
{
	short	set;
	double	real;
	double	imag;
	short	color;
}			t_param;

typedef struct s_coord
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}			t_coord;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*palette;
	t_coord	*coord;
	t_param	*param;
}			t_data;

void		show_valid_param(void);
t_bool		is_valid_param(int argc, char **argv);
void		get_param(t_param *param, char **argv);
t_bool		rendering(t_data *img, t_param *param);
int			create_trgb(short t, short r, short g, short b);
void		launch_rendering(t_data *img);
t_coord		*set_coordinate(t_coord *coord);
int			calculation_complex(double real, double imag, short iteration,
				t_data *img);
int			mouse_hook(int button, int x, int y, t_data *img);
int			key_hook(int button, t_data *img);
double		normalization(double min_to, double max_to, double max_from,
				short value);
void		my_mlx_pixel_put(t_data *data, short x, short y, short color);
void		color_white(int *palette);
void		color_blue(int *palette);
void		color_psyc(int *palette);
void		go_up(t_data *img);
void		go_down(t_data *img);
void		go_left(t_data *img);
void		go_right(t_data *img);
void		go_exit(t_data *img);
void		close_and_free(t_data *img);
int			cross_exit(t_data *img);

#endif
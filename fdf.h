/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:50 by wkraig            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/21 17:44:07 by wkraig           ###   ########.fr       */
=======
/*   Updated: 2020/02/21 16:33:51 by hcloves          ###   ########.fr       */
>>>>>>> dfee80662ea274bf4ae14a00615f9641b5a9868d
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
// разместить перемеггые и структуры для выравнивания 
typedef struct s_win
{
	int		**map;
	int		**color;
	void	*inter;
	int		size;
	int		fd;
	float	zoom;
	void	*ptr;
	void	*wind;
	float	start_x;
	float	start_y;
	float	z_zoom;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	bool	iso;
	bool	dv;
	bool	angle_is;
	// bool	y;
	bool	angle;
}				t_win;

typedef struct	s_map
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	x;
	float	y;
}				t_map;

typedef struct	s_figure
{
	int		len;
	float	move_x;
	float	move_y;
}				t_figure;

typedef struct	s_line
{
	float	d_act;
	float	d_real;
	float	x;
	float	y;
	float		step;
}				t_line;

<<<<<<< HEAD
void	draw_line_x(t_map coord, t_win *win, int z, int z0);
void	draw_line_y(t_map coord, t_win *win, int z, int z0);
int	keys(int key, t_win *win);
int		exit_form(int key, t_win *win);
void	create_figure(t_win *win, t_figure *changes);
int		ft_color(int z, int z0, t_win *win, int color);
=======
void    menu(t_win *menu);
>>>>>>> dfee80662ea274bf4ae14a00615f9641b5a9868d
void	angle(float *x, float *y, int *z, t_win *win);
void	draw_line_x(t_map coord, t_win *win, int z, int z0);
void	ft_swap(float *a, float *b);
float	ft_abs(float a);
void	iso(float *x, float *y, int z, t_win *win);
int		ft_atoi_base_16(char *str);
int		ft_numlen(char *res);
int		**split_to_arr(char **res, t_win *parse);
int		**parser(int fd, t_win *parse);
int ft_validation(char **map);
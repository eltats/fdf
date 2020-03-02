/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:50 by wkraig            #+#    #+#             */
/*   Updated: 2020/03/02 17:54:33 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_win
{
	int		**map;
	void	*inter;
	int		size;
	int		zoom;
	int		fd;
	int		z0;
	int		z;
	int		bonus;
	int		fd2;
	int		random;
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
	bool	angle;
}					t_win;

typedef struct		s_parse
{
	int		i;
	int		j;
	int		k;
	char	**map_l;
}					t_parse;

typedef struct		s_map
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	x;
	float	y;
}					t_map;

typedef struct		s_figure
{
	int		len;
	float	move_x;
	float	move_y;
}					t_figure;

typedef struct		s_line
{
	float	d_act;
	float	d_real;
	int		x;
	int		y;
	float	step;
}					t_line;

void				menu(t_win *menu);
int					music(int key);
int					keys(int key, t_win *win, char **av);
int					move_key(int key, t_win *win);
int					projection(int key, t_win *win);
int					change_color(int key, t_win *win);
int					change_z_zoom(int key, t_win *win);
int					exit_form(int key, t_win *win);
int					change_zoom(int key, t_win *win);
float				absolute(float x);
void				ft_swap(float *a, float *b);
float				ft_abs(float a);
int					ft_numlen(char *res);
int					ft_atoi_base_16(char *str);
int					ft_color(int z, int z0, t_win *win, int color);
void				create_figure(t_win *win, t_figure *changes);
void				loop_figure(t_win *win, t_map coord, int len);
int					**split_to_arr(int fd, t_win *parse, int file_len, int str_len);
int					**parser(int fd, t_win *win, char *filename);
int					ft_validation(char **map);
void				iso(float *x, float *y, int z, t_win *win);
void				bresenham_x(t_map copy, t_win *win, int z, int z0);
void				draw_line_x(t_map coord, t_win *win, int z, int z0);
void				zeloop_bresemham_x(t_line line,
					t_map copy, int color, t_win *win);
void				draw_proection_iso_x(t_map coord,
					t_win *win, int z, int z0);
void				asf(t_win *win, int z, int z0, t_map copy);
void				draw_line_y(t_map coord, t_win *win, int z, int z0);
void				bresenham_y(t_map copy, t_win *win, int z, int z0);
void				zeloop_bresemham_y(t_line line,
					t_map copy, int color, t_win *win);
void				draw_proection_iso_y(t_map coord,
					t_win *win, int z, int z0);
void				asf2(t_win *win, int z, int z0, t_map copy);

#endif

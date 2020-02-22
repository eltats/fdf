/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:50 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/22 21:28:58 by hcloves          ###   ########.fr       */
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
}				t_win;

typedef struct	s_parse
{
	int		i;
	int		j;
	int		k;
	char	**map_l;
}				t_parse;

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



void    menu(t_win *menu);
void	draw_line_x(t_map coord, t_win *win, int z, int z0, int bonus);
void	ft_swap(float *a, float *b);
float	ft_abs(float a);
void	iso(float *x, float *y, int z, t_win *win);
int		ft_atoi_base_16(char *str);
int		ft_numlen(char *res);
int		**split_to_arr(t_parse	*prs, t_win *parse);
int		**parser(int fd, t_win *parse);
int 	ft_validation(char **map);
int		keys(int key, t_win *win, char **av);
void	create_figure(t_win *win, t_figure *changes);
int     move_key(int key, t_win *win);
int     projection(int key, t_win *win);
int     change_color(int key, t_win *win);
int     change_z_zoom(int key, t_win *win);
void	draw_proection_iso_x(t_map coord, t_win *win, int z, int z0);
void	draw_proection_iso_y(t_map coord, t_win *win, int z, int z0);
void	asf(t_win *win, int z, int z0, t_map copy, int bonus);
void	asf2(t_win *win, int z, int z0, t_map copy, int bonus);
float	absolute(float x);
int		exit_form(int key, t_win *win);
int		ft_color(int z, int z0, t_win *win, int color);

void	bresenham_x(t_map copy, t_win *win, int z, int z0, int bonus);
void	draw_line_x(t_map coord, t_win *win, int z, int z0, int bonus);
void	zaloop_bresemham_x(t_line line, t_map copy, int color, t_win *win);

void	draw_line_y(t_map coord, t_win *win, int z, int z0, int bonus);
void	bresenham_y(t_map copy, t_win *win, int z, int z0, int bonus);
void	zaloop_bresemham_y(t_line line, t_map copy, int color, t_win *win);
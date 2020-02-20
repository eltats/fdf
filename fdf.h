/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:50 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/20 07:44:21 by wkraig           ###   ########.fr       */
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
	int		size;
	int		fd;
	void	*ptr;
	void	*wind;
	float	start_x;
	float	start_y;
	float	z_zoom;
	float	angle_x;
	bool	iso_f;
	bool	y;
	bool	dv;
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

void	ft_swap(float *a, float *b);
float	ft_abs(float a);
void	iso(float *x, float *y, int z, t_win *win);
int		ft_atoi_base_16(char *str);
int		ft_numlen(char *res);
int		**split_to_arr(char **res, t_win *parse);
int		**parser(int fd, t_win *parse);
int ft_validation(char **map);
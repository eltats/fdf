/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:50 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/17 17:58:05 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <math.h>
#include <stdio.h>

typedef struct s_win
{
	void	*ptr;
	void	*wind;
}				t_win;

typedef struct	s_map
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	start_x;
	float	start_y;
	float	x;
	float	y;
}				t_map;

typedef struct	s_line
{
	float	d_act;
	float	d_real;
	float	x;
	float	y;
	int		step;
}				t_line;

typedef struct s_data
{
	int		**map;
	int		**color;
	int		size;
}			t_data;

int		ft_atoi_base_16(char *str);
int		ft_numlen(char *res);
int		**split_to_arr(char **res, t_data *parse);
int		**parser(int fd, t_data *parse);
int ft_validation(char **map);
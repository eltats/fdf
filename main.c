/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:48 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/17 18:57:38 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_from(int key, void *param)
{
	if (key == 53)
		exit(0);
	return (0);
}

float absolute(float x)
{
	if (x < 0) return -x;
	else	return x;
	
}
void	ft_swap(float *a, float *b)
{
	float tmp;

	tmp = *b;
	*a = *a + *b;
	*b = *a - *b;
	*a = tmp;
}

float	ft_abs(float a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

void	draw_line_x(t_map *coord, t_win *win)
{
	t_line	line;
	t_map	*copy;

	ft_bzero(&line, sizeof(line));
	copy = coord;
	line.step = 1;
	line.d_real = ft_abs(copy->y2 - copy->y1) / ft_abs(copy->x2 - copy->x1);
	if (copy->x1 > copy->x2)
	{
		ft_swap(&copy->x1, &copy->x2);
		ft_swap(&copy->y1, &copy->y2);
	}
	line.x = copy->x1;
	line.y = copy->y1;
	if (line.y < copy->y2)
		line.step = -1;
	line.d_act = 0;
	while (line.x < copy->x2)
	{
		line.x++;
		line.d_act += line.d_real;
		if (line.d_act > 0.5)
		{
			line.y += line.step;
			line.d_act -= 1.0;
		}
		mlx_pixel_put(win->ptr, win->wind, copy->start_x + (int)line.x, copy->start_y + (int)line.y, 0xAFFFFF);
	}
}

void	draw_line_y(t_map *coord, t_win *win)
{
	t_line	line;
	t_map	*copy;

	ft_bzero(&line, sizeof(line));
	copy = coord;
	line.step = 1;
	line.d_real = ft_abs(copy->x2 - copy->x1) / ft_abs(copy->y2 - copy->y1);
	if (copy->y1 > copy->y2)
	{
		ft_swap(&copy->y1, &copy->y2);
		ft_swap(&copy->x1, &copy->x2);
	}
	line.x = copy->x1;
	line.y = copy->y1;
	if (line.x < copy->x2)
		line.step = -1;
	line.d_act = 0;
	while (line.y < copy->y2)
	{
		line.y++;
		line.d_act += line.d_real;
		if (line.d_act > 0.5)
		{
			line.x += line.step;
			line.d_act -= 1.0;
		}
		mlx_pixel_put(win->ptr, win->wind, (int)copy->start_x + (int)line.x, (int)copy->start_y + (int)line.y, 0xAFFFFF);
	}
}

void	create_figure(t_win *win, t_data *data)
{
	int		i;
	int		j;
	t_map	coord;
	float	isox;
	float	isox1;
	float	isoy;
	float	isoy1;
	float	temp_y;
	float	temp_x;
	float	temp_y1;
	float	temp_x1;

	i = 0;
	ft_bzero(&coord, sizeof(t_map));
	while (data->map[i])
		i++;
	coord.start_x = 2000 / i;
	coord.start_y = 1200 / data->size;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		coord.x = 0;
		while (j <= data->size)
		{
			coord.x1 = coord.start_x + coord.x;
			coord.x2 = coord.start_x + coord.x + 25;
			coord.y1 = coord.start_y + coord.y;
			coord.y2 = coord.start_y + coord.y;
			// isox = coord.x1 - coord.y1;
			// isoy = (coord.x1 + coord.y1) / 2;
			// coord.x1 = isox;
			// coord.y1 = isoy;
			// isox1 = coord.x2 - coord.y2;
			// isoy1 = (coord.x2 + coord.y2) / 2;
			// coord.x2 = isox1;
			// coord.y2 = isoy1;
			if (j != data->size)
				draw_line_x(&coord, win);
			coord.y2 += 25;
			coord.x2 = coord.x1;
			draw_line_y(&coord, win);
			coord.x += 25;
			j++;
		}
		coord.y += 25;
		i++;
	}
}

int main(int ac, char **av)
{
	t_win	*win;
	t_data	*parse;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		parse = (t_data *)ft_memalloc(sizeof(t_data));
		win = (t_win *)ft_memalloc(sizeof(t_win));
		parse->map = parser(fd, parse);
		win->ptr = mlx_init();
		win->wind = mlx_new_window(win->ptr, 2000, 1200, "roflan");
		create_figure(win, parse);
		mlx_key_hook(win->wind, exit_from, (void *)0);
		mlx_loop(win->ptr);
	}
	return (0);
}

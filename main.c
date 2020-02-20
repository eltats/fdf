/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:48 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/20 08:01:12 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	draw_line_x(t_map coord, t_win *win, int z, int z0);

void	draw_line_y(t_map coord, t_win *win, int z, int z0)
{
	t_line	line;
	t_map	copy;

	int		color;
	color = 0xAFFFFF;
	ft_bzero(&line, sizeof(line));
	copy = coord;
	if (win->dv == false)
		copy.y2 += 25;
	if (z || z0)
		color = 0xFF0000;
	if (win->iso_f && win->dv == false)
	{
		iso(&copy.x1, &copy.y1, z * win->z_zoom, win);
		iso(&copy.x2, &copy.y2, z0 * win->z_zoom, win);
	}
	if (ft_abs(copy.x2 - copy.x1) > ft_abs(copy.y2 - copy.y1))
	{
		win->dv = true;
		draw_line_x(copy, win, z, z0);
		win->dv = false;
		return ; 
	}
	line.step = 1;
	line.d_real = ft_abs(copy.x2 - copy.x1) / ft_abs(copy.y2 - copy.y1);
	if (copy.y1 > copy.y2)
	{
		ft_swap(&copy.y1, &copy.y2);
		ft_swap(&copy.x1, &copy.x2);
	}
	line.x = copy.x1;
	line.y = copy.y1;
	if (line.x > copy.x2)
		line.step = -1;
	line.d_act = 0;
	while (line.y <= copy.y2)
	{
		mlx_pixel_put(win->ptr, win->wind, (int)line.x, (int)line.y, color);
		line.y++;
		line.d_act += line.d_real;
		if (line.d_act > 0.5)
		{
			line.x += line.step;
			line.d_act--;
		}
	}
}

void	draw_line_x(t_map coord, t_win *win, int z, int z0)
{
	t_line	line;
	t_map	copy;
	int		color;

	ft_bzero(&line, sizeof(line));
	copy = coord;
	if (win->dv == false)
		copy.x2 += 25;
	color = 0xAFFFFF;
	if (z || z0)
		color = 0xFF0000;
	if (win->iso_f && win->dv == false)
	{
		iso(&copy.x1, &copy.y1, z * win->z_zoom, win);
		iso(&copy.x2, &copy.y2, z0 * win->z_zoom, win);
	}
	if (ft_abs(copy.x2 - copy.x1) < ft_abs(copy.y2 - copy.y1))
	{
		win->dv = true;
		draw_line_y(copy, win, z, z0);
		win->dv = false;
		return ; 
	}
	line.step = 1;
	line.d_real = ft_abs(copy.y2 - copy.y1) / ft_abs(copy.x2 - copy.x1);
	if (copy.x1 > copy.x2)
	{
		ft_swap(&copy.x1, &copy.x2);
		ft_swap(&copy.y1, &copy.y2);
	}
	line.x = copy.x1;
	line.y = copy.y1;
	if (line.y > copy.y2)
		line.step = -1;
	line.d_act = 0;
	while (line.x <= copy.x2)
	{
		mlx_pixel_put(win->ptr, win->wind, (int)line.x, (int)line.y, color);
		line.x++;
		line.d_act += line.d_real;
		if (line.d_act > 0.5)
		{
			line.y += line.step;
			line.d_act--;
		}
	}
}

void	ft_draw(t_map coord, t_win *win, int z, int z0)
{
	t_map copy;

	copy = coord;
	if (win->y == true)
	{
		win->y = false;
		copy.y2 += 25;
	}
	else
		copy.x2 += 25;
	if (ft_abs(copy.x2 - copy.x1) > ft_abs(copy.y2 - copy.y1))
		draw_line_x(coord, win, z, z0);
	else
		draw_line_y(coord, win, z, z0);
}

void	create_figure(t_win *win, t_figure *changes)
{
	int		i;
	int		j;
	int		len;
	t_map	coord;

	len = 0;
	ft_bzero(&coord, sizeof(t_map));
	while (win->map[len])
		len++;
	if (changes->move_x != 0)
	{
		win->start_x -= changes->move_x;
	}
	if (changes->move_y != 0)
	{
		win->start_y -= changes->move_y;
	}
	i = 0;
	coord.y = 0;
	while (win->map[i])
	{
		j = 0;
		coord.x = 0;
		while (j <= win->size)
		{
			coord.x1 = win->start_x + coord.x;
			coord.x2 = win->start_x + coord.x;
			coord.y1 = win->start_y + coord.y;
			coord.y2 = win->start_y + coord.y;
			if (j < win->size - 1)
				// ft_draw(coord, win, win->map[i][j], win->map[i][j + 1]);
				draw_line_x(coord, win, win->map[i][j], win->map[i][j + 1]);
			if (i < len - 1 && j < win->size)
			{
				win->y = true;
				// ft_draw(coord, win, win->map[i][j], win->map[i][j + 1]);
				draw_line_y(coord, win, win->map[i][j], win->map[i + 1][j]);
			}
			coord.x += 25;
			j++;
		}
		coord.y += 25;
		i++;
	}
}

int	keys(int key, t_win *win)
{
	t_figure *changes;
//  
	printf("%d\n", key);
	changes = (t_figure *)ft_memalloc(sizeof(t_figure));
	if (key == 123 || key == 124)
	{
		changes->move_x = 25;
		key == 124 ? changes->move_x = -25 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 126 || key == 125)
	{
		changes->move_y = 25;
		key == 125 ? changes->move_y = -25 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 35)
	{
		win->iso_f = false;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 47)
	{
		if (win->z_zoom < 60)
			win->z_zoom *= 1.1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 43)
	{
		if (win->z_zoom > 1)
			win->z_zoom /= 1.1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 91 || key == 84)
	{
		win->angle_x += 0.1;
		key == 84 ? win->angle_x -= 0.2 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	return (0);
}

int		exit_form(int key, void *param)
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

int main(int ac, char **av)
{
	t_win	*win;
	t_figure	*changes;
	t_map	copy;

	if (ac == 2)
	{
		win = (t_win *)ft_memalloc(sizeof(t_win));
		win->fd = open(av[1], O_RDONLY);
		win->map = parser(win->fd, win);
		win->ptr = mlx_init();
		changes = (t_figure *)ft_memalloc(sizeof(t_figure));
		win->wind = mlx_new_window(win->ptr, 2000, 1200, "roflan");
		win->iso_f = true;
		win->z_zoom = 1;
		win->angle_x = 1;
		win->dv = false;
		create_figure(win, changes);
		mlx_key_hook(win->wind, exit_form, (void *)0);
		mlx_hook(win->wind, 2, 0, keys, win);
		mlx_loop(win->ptr);
	}
	return (0);
}

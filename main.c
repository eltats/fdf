/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:48 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/23 18:12:34 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(int z, int z0, t_win *win, int color)
{
	color = 0x5A009D;
	if (z * win->z_zoom > 0 || z0 * win->z_zoom > 0)
		color = 0x96009D;
	if (z * win->z_zoom > 20 || z0 * win->z_zoom > 20)
		color = 0x96009D;
	if (z * win->z_zoom > 40 || z0 * win->z_zoom > 40)
		color = 0x9B009D;
	if (z * win->z_zoom > 60 || z0 * win->z_zoom > 60)
		color = 0xA0009D;
	if (z * win->z_zoom > 80 || z0 * win->z_zoom > 80)
		color = 0xA5009D;
	if (z * win->z_zoom > 100 || z0 * win->z_zoom > 100)
		color = 0xAA009D;
	if (z * win->z_zoom > 120 || z0 * win->z_zoom > 120)
		color = 0xB4009D;
	if (z * win->z_zoom > 140 || z0 * win->z_zoom > 140)
		color = 0xB9009D;
	if (z * win->z_zoom > 160 || z0 * win->z_zoom > 160)
		color = 0xBE009D;
	else if (z * win->z_zoom > 160 || z0 * win->z_zoom > 160)
		color = 0xCD009D;
	if (win->random != 1)
		color += win->random;
	return (color);
}

// void	zxc(int i, int j, t_map coord, t_win *win)
// {
	
// 				win->z = win->map[i][j];
// 				win->z0 = win->map[i][j + 1];
// 				win->bonus = win->color[i][j];
// 				draw_line_x(coord, win);
// }
void	loop_figure(t_win *win, t_map coord, int len)
{
	int		i;
	int		j;
	
	i = 0;
	while (win->map[i])
	{
		j = 0;
		coord.x = 1000;
		while (j <= win->size)
		{
			coord.x1 = win->start_x + coord.x;
			coord.x2 = win->start_x + coord.x;
			coord.y1 = win->start_y + coord.y;
			coord.y2 = win->start_y + coord.y;
			if (j < win->size - 1)
				draw_line_x(coord, win, win->map[i][j], win->map[i][j + 1], win->bonus);
			if (i < len - 1 && j < win->size)
				draw_line_y(coord, win, win->map[i][j], win->map[i + 1][j], win->bonus);
			coord.x += 25;
			j++;
		}
		coord.y += 25;
		i++;
	}
}

void	create_figure(t_win *win, t_figure *changes)
{
	int		len;
	t_map	coord;

	len = 0;
	ft_bzero(&coord, sizeof(t_map));
	while (win->map[len])
		len++;
	if (changes->move_x != 0)
		win->start_x += changes->move_x;
	if (changes->move_y != 0)
		win->start_y += changes->move_y;
	coord.y = 500;
	loop_figure(win, coord, len);
	menu(win);
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
		win->wind = mlx_new_window(win->ptr, 2000, 1200, "FdF");		
		win->random = 1;
		win->iso = false;
		win->z_zoom = 1;
		win->dv = false;
		create_figure(win, changes);
		mlx_key_hook(win->wind, exit_form, win);
		mlx_hook(win->wind, 2, 0, keys, win);
		mlx_loop(win->ptr);
		close(win->fd);
	}
	return (0);
}

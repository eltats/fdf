/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:48 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/21 20:25:48 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_figure(t_win *win, t_figure *changes)
{
	int		i;
	int		j;
	int		len;
	t_map	coord;
	t_map	copy;

	ft_bzero(&coord, sizeof(t_map));
	if (changes->move_x != 0)
		win->start_x += changes->move_x;
	if (changes->move_y != 0)
		win->start_y += changes->move_y;
	len = 0;
	while (win->map[len])
		len++;
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
				draw_line_x(coord, win, win->map[i][j], win->map[i][j + 1]);
			if (i < len - 1 && j < win->size)
				draw_line_y(coord, win, win->map[i][j], win->map[i + 1][j]);
			coord.x += 1 * win->zoom;
			j++;
		}
		coord.y += 1  * win->zoom;
		i++;
	}
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
		if (win->fd < 0)
			return (0);
		if (!(win->map = parser(win->fd, win)))
			return (0);
		win->ptr = mlx_init();
		changes = (t_figure *)ft_memalloc(sizeof(t_figure));
		win->wind = mlx_new_window(win->ptr, 2000, 1200, "FdF");
		// win->iso = true;
		win->iso = false;
		win->z_zoom = 1;
		win->dv = false;
		win->zoom = 20;
		create_figure(win, changes);
		mlx_key_hook(win->wind, exit_form, win);
		mlx_hook(win->wind, 2, 0, keys, win);
		mlx_loop(win->ptr);
		close(win->fd);
		free(win);
		free (win->map);
		free(changes);
	}
	return (0);
}

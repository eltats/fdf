/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:48 by wkraig            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/21 20:25:48 by wkraig           ###   ########.fr       */
=======
/*   Updated: 2020/02/21 17:29:49 by hcloves          ###   ########.fr       */
>>>>>>> dfee80662ea274bf4ae14a00615f9641b5a9868d
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
	coord.y = 500;
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
				draw_line_x(coord, win, win->map[i][j], win->map[i][j + 1]);
			if (i < len - 1 && j < win->size)
				draw_line_y(coord, win, win->map[i][j], win->map[i + 1][j]);
			coord.x += 1 * win->zoom;
			j++;
		}
		coord.y += 1  * win->zoom;
		i++;
	}
	menu(win);
}

<<<<<<< HEAD
=======
int	keys(int key, t_win *win)
{
	t_figure *changes;

	// printf("%d\n", key);
	changes = (t_figure *)ft_memalloc(sizeof(t_figure));
	if (key == 123 || key == 124)
	{
		changes->move_x += 25;
		key == 124 ? changes->move_x -= 50 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 126 || key == 125)
	{
		changes->move_y += 25;
		key == 125 ? changes->move_y -= 50 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 35)
	{
		win->iso = false;
		// else
		// 	win->iso = true;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 34)
	{
		// if (win->iso == true)
		// 	
		win->iso = true;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 47)
	{
		if (win->z_zoom < 60 && win->angle == false)
			win->z_zoom *= 1.1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 43)
	{
		//win->iso = true;

		if (win->z_zoom > 1)
			win->z_zoom /= 1.1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 91 || key == 84)
	{
		win->angle = true;
		win->angle_x += 0.1;
		key == 84 ? win->angle_x -= 0.2 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
		win->angle = false;
	}
	if (key == 86 || key == 88)
	{
		win->angle_y += 0.1;
		key == 88 ? win->angle_y -= 0.2 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	return (0);
}

int		exit_form(int key, t_win *win)
{
	if (key == 53)
	{
		close(win->fd);
		exit(0);
	}
	return (0);
}

float absolute(float x)
{
	if (x < 0) return -x;
	else	return x;
	
}

>>>>>>> dfee80662ea274bf4ae14a00615f9641b5a9868d
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
<<<<<<< HEAD
		win->wind = mlx_new_window(win->ptr, 2000, 1200, "FdF");
		// win->iso = true;
=======
		win->wind = mlx_new_window(win->ptr, 2000, 1200, "FdF");		
		//mlx_string_put (win->ptr, win->wind, 300, 500, 0xAA009D, "Hello");
		//menu(win);
		//win->inter = mlx_new_window(win->ptr, 500, 1200, "Interface");
>>>>>>> dfee80662ea274bf4ae14a00615f9641b5a9868d
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

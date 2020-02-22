/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:38:36 by hcloves           #+#    #+#             */
/*   Updated: 2020/02/22 19:39:13 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     move_key(int key, t_win *win)
{
    t_figure *changes;

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
    return (0);
}

int     projection(int key, t_win *win)
{
    t_figure *changes;

	changes = (t_figure *)ft_memalloc(sizeof(t_figure));
    if (key == 35)
	{
		win->iso = false;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 34)
	{	
		win->iso = true;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
    return (0);
}

int     change_color(int key, t_win *win)
{
    t_figure *changes;

	changes = (t_figure *)ft_memalloc(sizeof(t_figure));
	if (key == 49)
	{
		win->random = (int)changes;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 15)
	{
		win->random = 1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
    return (0);
}

int     change_z_zoom(int key, t_win *win)
{
    t_figure *changes;

	changes = (t_figure *)ft_memalloc(sizeof(t_figure));
    if (key == 47)
	{
		if (win->z_zoom < 60 && win->angle == false)
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
    return (0);
}

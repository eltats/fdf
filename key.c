/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:37:39 by hcloves           #+#    #+#             */
/*   Updated: 2020/02/23 20:26:17 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keys(int key, t_win *win, char **av)
{
	t_figure *changes;
	int fd;
	
	changes = (t_figure *)ft_memalloc(sizeof(t_figure));
    printf("%d\n", key);
    if (key == 5)
    {
		system("pkill afplay -t 5");
		system("afplay GIMN.mp3 &> /dev/null &");
    }
    if (key == 123 || key == 124 || key == 126 || key == 125)
        move_key(key, win);
	if (key == 69)
	{
		if (win->zoom < 40)
			win->zoom += 1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 78)
	{
		if (win->zoom > 5)
			win->zoom -= 1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 35 || key == 34)
        projection(key, win);
	if (key == 47 || key == 43)
        change_z_zoom(key, win); 
	if (key == 49 || key == 15)
        change_color(key, win);
	if (key == 3)
	{
		system("exit afplay");
	}
	return (0);
}
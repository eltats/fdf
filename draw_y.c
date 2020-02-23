/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:37:28 by hcloves           #+#    #+#             */
/*   Updated: 2020/02/23 20:35:24 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	asf(t_win *win, int z, int z0, t_map copy)
{
	win->dv = true;
	draw_line_x(copy, win, z, z0);
	win->dv = false;
	return ; 
}

void	zaloop_bresemham_y(t_line line, t_map copy, int color, t_win *win)
{
	while (line.y <= copy.y2)
	{
		mlx_pixel_put(win->ptr, win->wind, (int)line.x, (int)line.y, color * win->random);
		line.y++;
		line.d_act += line.d_real;
		if (line.d_act > 0.5)
		{
			line.x += line.step;
			line.d_act--;
		}
	}
}

void	bresenham_y(t_map copy, t_win *win, int z, int z0)
{
	t_line line;
	int color;

	ft_bzero(&line, sizeof(line));
    color = ft_color(z, z0, win, color);
	if (ft_abs(copy.x2 - copy.x1) > ft_abs(copy.y2 - copy.y1))
		return (asf(win, z, z0, copy));
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
	zaloop_bresemham_y(line, copy, color, win);
}

void	draw_line_y(t_map coord, t_win *win, int z, int z0)
{
	t_map	copy;

	copy = coord;
	if (win->dv == false)
		copy.y2 += 1 * win->zoom;
	if (win->iso == true && win->dv == false)
	{
		iso(&copy.x1, &copy.y1, z * win->z_zoom, win);
		iso(&copy.x2, &copy.y2, z0 * win->z_zoom, win);
	}
	bresenham_y(copy, win, z, z0);
}

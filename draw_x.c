/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:37:16 by hcloves           #+#    #+#             */
/*   Updated: 2020/02/23 23:01:14 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	asf2(t_win *win, int z, int z0, t_map copy)
{
	win->dv = true;
	draw_line_y(copy, win, z, z0);
	win->dv = false;
	return ;
}

void	zeloop_bresemham_x(t_line line, t_map copy, int color, t_win *win)
{
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

void	bresenham_x(t_map copy, t_win *win, int z, int z0)
{
	t_line	line;
	int		color;

	ft_bzero(&line, sizeof(line));
	color = ft_color(z, z0, win, color);
	if (ft_abs(copy.y2 - copy.y1) > ft_abs(copy.x2 - copy.x1))
		return (asf2(win, z, z0, copy));
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
	zeloop_bresemham_x(line, copy, color, win);
}

void	draw_line_x(t_map coord, t_win *win, int z, int z0)
{
	t_map	copy;

	copy = coord;
	if (win->dv == false)
		copy.x2 += 1 * win->zoom;
	if (win->iso == true && win->dv == false)
	{
		iso(&copy.x1, &copy.y1, z * win->z_zoom, win);
		iso(&copy.x2, &copy.y2, z0 * win->z_zoom, win);
	}
	bresenham_x(copy, win, z, z0);
}

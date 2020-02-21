/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:43:13 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/21 20:45:12 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_proj(t_win *win, t_map *copy, int z, int z0)
{
	// int		z1;
	// int		z2;
	int			x2;
	int			y2;
	// z1 = (z * win->z_zoom) - win->zoom;
	// z2 = (z0 * win->z_zoom) -  win->zoom;

	if (!((z * win->z_zoom) - win->zoom <= z) && !((z * win->z_zoom) - win->zoom <= z0))
	{
		z = (z * win->z_zoom) - win->zoom;
		z0 = (z0 * win->z_zoom) - win->zoom;
	}
		// z1 = z;
	// if ((z * win->z_zoom) - win->zoom <= z0)
		// z2 = z0;
	x2 = copy->x1;
	y2 = copy->y1;
	copy->x1 = (x2 - y2) * cos(0.523599);
	copy->y1 = -((z * win->z_zoom) - win->zoom) + (x2 + y2) * sin(0.523599);
	x2 = copy->x2;
	y2 = copy->y2;
	copy->x2 = (x2 - y2) * cos(0.523599);
	copy->y2 = -((z0 * win->z_zoom) - win->zoom) + (x2 + y2) * sin(0.523599);
	// iso(&copy->x1, &copy->y1, z1, win);
	// iso(&copy->x2, &copy->y2, z2, win);
}

void	other_y(t_win *win, t_map copy, int z, int z0)
{

		win->dv = true;
		draw_line_x(copy, win, z, z0);
		win->dv = false;
		return ; 
}

// void	other_x(t_win *win, t_map copy, int z, int z0)
// {
// 	win->dv = true;
// 	draw_line_y(copy, win, z, z0);
// 	win->dv = false;
// 	return ; 
// }

void	draw_line_y(t_map coord, t_win *win, int z, int z0)
{
	t_line	line;
	t_map	copy;
	int		color;
	
	ft_bzero(&line, sizeof(line));
	copy = coord;
	if (win->dv == false)
		copy.y2 += 1 * win->zoom;
	if (win->iso == true && win->dv == false)
		iso_proj(win, &copy, z, z0);
	if (ft_abs(copy.x2 - copy.x1) > ft_abs(copy.y2 - copy.y1))
	{
		win->dv = true;
		draw_line_x(copy, win, z, z0);
		win->dv = false;
		return ; 
	}
		// return (other_y(win, copy, z, z0));
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
		mlx_pixel_put(win->ptr, win->wind, (int)line.x, (int)line.y, ft_color(z, z0, win, color));
		line.y++;
		line.d_act += line.d_real;
		if (line.d_act > 0.5)
		{
			line.x += line.step;
			line.d_act--;
		}
	}
}
t_line	line_init(t_map copy)
{
	t_line	line;

	ft_bzero(&line, (sizeof(t_line)));
	line.step = 1;
	line.d_real = ft_abs(copy.y2 - copy.y1) / ft_abs(copy.x2 - copy.x1);
	line.x = copy.x1;
	line.y = copy.y1;
	line.d_act = 0;
	return (line);
}

void	swap(t_map *copy)
{
	ft_swap(&copy->y1, &copy->y2);
	ft_swap(&copy->x1, &copy->x2);
}

void	draw_line_x(t_map coord, t_win *win, int z, int z0)
{
	t_line	line;
	t_map	copy;
	int		color;
	
	copy = coord;
	ft_bzero(&line, (sizeof(t_line)));
	if (win->dv == false)
		copy.x2 += 1 * win->zoom;
	if (win->iso == true && win->dv == false)
		iso_proj(win, &copy, z, z0);
	if (ft_abs(copy.y2 - copy.y1) > ft_abs(copy.x2 - copy.x1))
		return (other_y(win, copy, z, z0));
	if (copy.x1 > copy.x2)
		swap(&copy);
	line.step = 1;
	line.d_real = ft_abs(copy.y2 - copy.y1) / ft_abs(copy.x2 - copy.x1);
	line.x = copy.x1;
	line.y = copy.y1;
	line.d_act = 0;
	if (line.y > copy.y2)
		line.step = -1;
	while (line.x <= copy.x2)
	{
		// if (win->dv)
		mlx_pixel_put(win->ptr, win->wind, (int)line.x, (int)line.y, ft_color(z, z0, win, color));
		line.x++;
		line.d_act += line.d_real;
		if (line.d_act > 0.5)
		{
			line.y += line.step;
			line.d_act--;
		}
	}
}

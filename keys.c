#include "fdf.h"

int	keys(int key, t_win *win)
{
	t_figure *changes;

	// printf("%d\n", key);
	changes = (t_figure *)ft_memalloc(sizeof(t_figure));
	if (key == 123 || key == 124)
	{
		changes->move_x = -25;
		key == 124 ? changes->move_x = 25 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 126 || key == 125)
	{
		changes->move_y = -25;
		key == 125 ? changes->move_y = 25 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 35)
	{
		if (win->iso == true)
			win->iso = false;
		else
			win->iso = true;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 78)
	{
		if (win->zoom > 20)
			win->zoom -= 1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 69)
	{
		if (win->zoom < 40)
			win->zoom += 1;
		// printf("%f\n", win->zoom);
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
		if (win->z_zoom)
			win->z_zoom /= 1.1;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 91 || key == 84)
	{
		win->angle = true;
		win->angle_x += 0.1;
		key == 84 ? win->angle_x += -0.2 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	if (key == 86 || key == 88)
	{
		win->angle_y += 0.1;
		key == 88 ? win->angle_y -= 0.2 : 0;
		mlx_clear_window(win->ptr, win->wind);
		create_figure(win, changes);
	}
	free(changes);
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

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
		color = 0xAF009D;
	if (z * win->z_zoom > 140 || z0 * win->z_zoom > 140)
		color = 0xB4009D;
	if (z * win->z_zoom > 160 || z0 * win->z_zoom > 160)
		color = 0xB9009D;
	if (z * win->z_zoom > 180 || z0 * win->z_zoom > 180)
		color = 0xBE009D;
	else if (z * win->z_zoom > 180 || z0 * win->z_zoom > 180)
		color = 0xCD009D;
	return (color);
}

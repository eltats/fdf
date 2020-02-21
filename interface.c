#include "fdf.h"

void    menu(t_win *menu)
{
    void *mlx;
    void *win;

    mlx = menu->ptr;
    win = menu->wind;

    mlx_string_put(mlx, win, 65, 40, 0xFBCEB5, "Keys to control");
    mlx_string_put(mlx, win, 40, 70, 0xFBCEB5, "Move:      arrows");
    mlx_string_put(mlx, win, 40, 90, 0xFBCEB5, "ISO:       I");
    mlx_string_put(mlx, win, 40, 110, 0xFBCEB5, "Parralel:  P");
    mlx_string_put(mlx, win, 40, 130, 0xFBCEB5, "Zoom:     <|>");
    mlx_string_put(mlx, win, 40, 160, 0xFBCEB5, "           8");
    mlx_string_put(mlx, win, 40, 170, 0xFBCEB5, "Axis:     4 6");
    mlx_string_put(mlx, win, 40, 180, 0xFBCEB5, "           2 ");
    // mlx_string_put(mlx, win, 100, 70, 0xA0009D, "Hello");
    // mlx_string_put(mlx, win, 100, 80, 0xA0009D, "Hello");
    // mlx_string_put(mlx, win, 100, 90, 0xA0009D, "Hello");
    // mlx_string_put(mlx, win, 100, 100, 0xA0009D, "Hello");
    // mlx_string_put(mlx, win, 100, 110, 0xA0009D, "Hello");
    // mlx_string_put(mlx, win, 100, 120, 0xA0009D, "Hello");

}
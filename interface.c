/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:38:25 by hcloves           #+#    #+#             */
/*   Updated: 2020/02/23 22:09:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_win *menu)
{
	void	*mlx;
	void	*win;

	mlx = menu->ptr;
	win = menu->wind;
	mlx_string_put(mlx, win, 65, 40, 0xFBCEB5, "Keys to control");
	mlx_string_put(mlx, win, 40, 70, 0xFBCEB5, "Move:        arrows");
	mlx_string_put(mlx, win, 40, 100, 0xFBCEB5, "ISO:         I");
	mlx_string_put(mlx, win, 40, 130, 0xFBCEB5, "Parralel:    P");
	mlx_string_put(mlx, win, 40, 160, 0xFBCEB5, "Color:       Space/R");
	mlx_string_put(mlx, win, 40, 190, 0xFBCEB5, "Zoom z axis: <|>");
	mlx_string_put(mlx, win, 40, 220, 0xFBCEB5, "Zoom:        +|-");
	mlx_string_put(mlx, win, 40, 250, 0xFBCEB5, "Music:    MUSIC.mp3");
	mlx_string_put(mlx, win, 40, 270, 0xFBCEB5, "      (On = G)(Off = F)");
	mlx_string_put(mlx, win, 40, 300, 0xFBCEB5, "EXIT:        ESC");
}

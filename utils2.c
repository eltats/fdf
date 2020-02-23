/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:38:11 by hcloves           #+#    #+#             */
/*   Updated: 2020/02/23 23:20:10 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_form(int key, t_win *win)
{
	if (key == 53)
	{
		close(win->fd);
		system("killall afplay");
		exit(0);
	}
	return (0);
}

float	absolute(float x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int		music(int key)
{
	if (key == 5)
		system("afplay MUSIC.mp3 &> /dev/null &");
	if (key == 3)
		system("killall afplay");
	return (0);
}

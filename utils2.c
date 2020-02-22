/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:38:11 by hcloves           #+#    #+#             */
/*   Updated: 2020/02/22 19:38:13 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_form(int key, t_win *win)
{
	if (key == 53)
	{
		close(win->fd);
		exit(0);
	}
	return (0);
}

float absolute(float x)
{
	if (x < 0) return -x;
	else	return x;
}
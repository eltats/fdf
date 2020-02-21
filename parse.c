/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:45 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/21 20:01:47 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_filenum(char *res)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (res[i])
	{
		if (ft_isdigit(res[i]))
			len++;
		while (ft_isdigit(res[i]))
			i++;
		i++;
	}
	return (len);
}
int		**split_to_arr(char **res, t_win *parse)
{
	int		i;
	int		j;
	int		k;

	parse->color = (int **)ft_memalloc(sizeof(int *) * (ft_strlen(*res) + 1));
	parse->map = (int **)ft_memalloc(sizeof(int *) * (ft_strlen(*res) + 1));
	i = 0;
	while (res[i])
	{
		parse->color[i] = (int *)ft_memalloc(sizeof(int) * (ft_filenum(res[i]) + 1));
		parse->map[i] = (int *)ft_memalloc(sizeof(int) * (ft_filenum(res[i]) + 1));
		j = 0;
		k = 0;
		while (res[i][j])
		{
			if (ft_isdigit(res[i][j]) || res[i][j] == '-')
			{
				parse->map[i][k] = ft_atoi(&res[i][j]);
				while (ft_isdigit(res[i][j]) || res[i][j] == '-')
					j++;
				if (res[i][j] == ',')
				{
					j++;
					parse->color[i][k] = ft_atoi_base_16(&res[i][j]);
				}
				k++;
			}
			j++;
		}
		parse->size = k;
		i++;
	}
	parse->map[i] = NULL;
	parse->start_x = 0;
	parse->start_y = 0;
	return (parse->map);
}

int		**parser(int fd, t_win *win)
{
	char	buf[251];
	char	*line;
	int		ret;
	char	**map;

	line = NULL;
	while((ret = read(fd, buf, 250)))
	{
		if (ret < 0)
			return (0);
		buf[ret] = '\0';
		if (!line)
			line = ft_strnew(1);
		line = ft_strjoin(line, buf);
	}
	map = ft_strsplit(line, '\n');
	return (split_to_arr(map, win));
}

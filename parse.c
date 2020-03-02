/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:45 by wkraig            #+#    #+#             */
/*   Updated: 2020/03/02 17:53:22 by wkraig           ###   ########.fr       */
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

void	get_numbers(int *file_len, int *str_len, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (i == 0)
			j = ft_filenum(map[i]);
		i++;
	}
	*file_len = i;
	*str_len = j;
}

int		**split_to_arr(int fd, t_win *parse, int file_len, int str_len)
{
	int		**matrix;
	int		i;
	int		j;
	int		k;
	char	*line;

	matrix = (int **)ft_memalloc(sizeof(int *) * (file_len + 1));
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		matrix[i] = (int *)ft_memalloc(sizeof(int) * (str_len));
		j = 0;
		k = 0;
		while (line[j])
		{
			if (ft_isdigit(line[j]) || line[j] == '-')
			{
				matrix[i][k] = ft_atoi(&line[j]);
				while (ft_isdigit(line[j]) || line[j] == '-')
					j++;
				k++;
			}
			j++;
		}
		i++;
	}
	parse->size = k;
	matrix[i] = NULL;
	return (matrix);
}

int		**parser(int fd, t_win *win, char *filename)
{
	char	*line;
	int		i;
	int		len;
	int		**matrix;

	i = 0;
	len = 0;
	while((get_next_line(fd, &line)) > 0)
	{
		if (i == 0)
			len = ft_filenum(line);
		i++;
		free(line);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	matrix = split_to_arr(fd, win, i, len);
	return (matrix);
}

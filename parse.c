/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:45 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/23 23:29:33 by hcloves          ###   ########.fr       */
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

void	big_if(t_parse *prs, t_win *parse)
{
	while (prs->map_l[prs->i][prs->j])
	{
		if (ft_isdigit(prs->map_l[prs->i][prs->j])
		|| prs->map_l[prs->i][prs->j] == '-')
		{
			parse->map[prs->i][prs->k] = ft_atoi(&prs->map_l[prs->i][prs->j]);
			while (ft_isdigit(prs->map_l[prs->i][prs->j])
			|| prs->map_l[prs->i][prs->j] == '-')
				prs->j++;
			if (prs->map_l[prs->i][prs->j] == ',')
			{
				prs->j++;
				parse->color[prs->i][prs->k] =
				ft_atoi_base_16(&prs->map_l[prs->i][prs->j]);
			}
			prs->k++;
		}
		prs->j++;
	}
}

int		**split_to_arr(t_parse *prs, t_win *parse)
{
	parse->color = (int **)ft_memalloc(sizeof(int *)
	* (ft_strlen(*prs->map_l) + 1));
	parse->map = (int **)ft_memalloc(sizeof(int *)
	* (ft_strlen(*prs->map_l) + 1));
	while (prs->map_l[prs->i])
	{
		parse->color[prs->i] = (int *)ft_memalloc(sizeof(int)
		* (ft_filenum(prs->map_l[prs->i]) + 1));
		parse->map[prs->i] = (int *)ft_memalloc(sizeof(int)
		* (ft_filenum(prs->map_l[prs->i]) + 1));
		prs->j = 0;
		prs->k = 0;
		big_if(prs, parse);
		parse->size = prs->k;
		prs->i++;
	}
	parse->map[prs->i] = NULL;
	parse->start_x = 0;
	parse->start_y = 0;
	return (parse->map);
}

int		**parser(int fd, t_win *win)
{
	char	buf[251];
	char	*line;
	int		ret;
	int		**retyrn;
	t_parse	*prs;

	line = NULL;
	ft_bzero(buf, 251);
	prs = (t_parse *)ft_memalloc(sizeof(t_parse));
	while ((ret = read(fd, buf, 250)) > 0)
	{
		buf[ret] = '\0';
		if (!line)
			line = ft_strnew(1);
		line = ft_strjoin(line, buf);
	}
	prs->map_l = ft_strsplit(line, '\n');
	free(line);
	retyrn = split_to_arr(prs, win);
	free(prs);
	return (retyrn);
}

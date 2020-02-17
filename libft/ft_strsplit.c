/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:25:48 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/27 16:06:09 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		start;
	int		i;
	int		j;

	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		start = i;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			str[j] = ft_strsub(s, start, i - start);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

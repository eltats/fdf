/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:20:44 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/02 20:12:08 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		first;
	char	*str;

	if (s)
	{
		len = ft_strlen(s);
		while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
			len--;
		first = -1;
		while (s[++first] == ' ' || s[first] == '\t' || s[first] == '\n')
			len--;
		if (len <= 0)
			len = 0;
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = -1;
		while (++i < len)
			str[i] = s[first++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

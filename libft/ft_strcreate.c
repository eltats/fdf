/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimfromstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:12:58 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/11 16:59:34 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcreate(char *s, int start, int end)
{
	char	*str;
	int		size;
	int		j;

	if (end <= 0)
		end++;
	size = end - start + 1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	j = 0;
	while (start <= end)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

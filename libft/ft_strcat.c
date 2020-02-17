/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:38:44 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/06 22:17:46 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (destination[i])
		i++;
	while (append[j])
	{
		destination[i + j] = append[j];
		j++;
	}
	destination[i + j] = '\0';
	return (destination);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:36:03 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/20 22:39:57 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (size + 1 < size)
		return (NULL);
	if (size == 0)
		return (0);
	if (!(str = malloc(size)))
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}

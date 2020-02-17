/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:23:03 by wkraig            #+#    #+#             */
/*   Updated: 2020/01/08 13:56:31 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_numbers(n);
	if (!(str = (char *)malloc(sizeof(char) * (ft_numbers(n) + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == -2147483648)
	{
		str[1] = '2';
		n = -147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:58:09 by wkraig            #+#    #+#             */
/*   Updated: 2019/10/16 18:59:11 by blord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_checkf(long long int result, long long int sign)
{
	if ((result * sign) < 0)
	{
		if (sign > 0)
			return (-1);
	}
	if ((result * sign) > 0)
	{
		if (sign < 0)
			return (0);
	}
	return (1);
}

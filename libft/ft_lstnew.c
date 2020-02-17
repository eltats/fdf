/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:16:00 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/14 15:32:05 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *fzm;

	if (!(fzm = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		fzm->content = NULL;
		fzm->content_size = 0;
	}
	if (content)
	{
		if (!(fzm->content = malloc(content_size)))
		{
			free(fzm);
			return (NULL);
		}
		ft_memcpy(fzm->content, content, content_size);
		fzm->content_size = content_size;
	}
	fzm->next = NULL;
	return (fzm);
}

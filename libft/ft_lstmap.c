/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 00:16:06 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/14 15:42:19 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*node;
	size_t	i;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	node = new;
	i = 0;
	while (lst->next)
	{
		i++;
		lst = lst->next;
		if (!(node->next = f(lst)))
		{
			free(node->next);
			return (NULL);
		}
		node = node->next;
	}
	return (new);
}

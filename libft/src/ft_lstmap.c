/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:34:15 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/16 17:03:06 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *newlist;
	t_list *tmp;

	if ((!lst) || (!f))
		return (NULL);
	tmp = (*f)(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	newlist = new;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		lst = lst->next;
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new = new->next;
	}
	new->next = NULL;
	return (newlist);
}

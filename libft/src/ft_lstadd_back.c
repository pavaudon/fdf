/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:40:26 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/16 15:51:42 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	if ((!lst) || (!new))
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	if (new->next)
		new->next = NULL;
}

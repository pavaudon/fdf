/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:12:15 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/16 14:04:02 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*tmp;
	t_list	*previous;

	tmp = *alst;
	while (tmp)
	{
		previous = tmp;
		free(tmp->content);
		free(previous);
		tmp = tmp->next;
	}
	*alst = NULL;
}

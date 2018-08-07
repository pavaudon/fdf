/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:44:47 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 19:44:49 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabffjoin(int *tab, int *to_add, int tablen, int to_addlen)
{
	int *new;

	if (!(new = (int*)ft_memalloc(sizeof(int) * (tablen + to_addlen))))
		return (NULL);
	ft_tabcpy(tab, new, tablen);
	ft_tabcpy(to_add, new + tablen, to_addlen);
	free(tab);
	return (new);
}

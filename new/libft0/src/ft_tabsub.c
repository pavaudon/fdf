/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:04:36 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/08 16:04:38 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabsub(int *tab, int start, int len)
{
	int *new;
	int i;

	i = -1;
	if (!(new = (int*)ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (++i < len)
		new[i] = tab[i + start];
	free(tab);
	return (new);
}

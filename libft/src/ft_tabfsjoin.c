/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfsjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:56:43 by pavaudon          #+#    #+#             */
/*   Updated: 2018/05/17 15:56:44 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabfsjoin(int *tab, int *to_add, int tablen, int to_addlen)
{
	int *new;

	if (!(new = (int*)ft_memalloc(sizeof(int) * (tablen + to_addlen))))
		return (NULL);
	ft_tabcpy(tab, new, tablen);
	ft_tabcpy(to_add, new + tablen, to_addlen);
	free(to_add);
	return (new);
}

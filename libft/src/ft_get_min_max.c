/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:07:19 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 19:07:20 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_min_max(int *tab, char *wich)
{
	int value;
	int i;

	i = -1;
	value = tab[0];
	while (tab[++i])
	{
		if (ft_strcmp("min", wich))
			value = (tab[i] < value) ? tab[i] : value;
		if (ft_strcmp("max", wich))
			value = (tab[i] > value) ? tab[i] : value;
	}
	return (value);
}

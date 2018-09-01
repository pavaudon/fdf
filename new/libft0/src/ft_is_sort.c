/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:21:53 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/15 16:21:55 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int len)
{
	int i;
	int j;

	i = -1;
	if (len == 0)
		return (0);
	while (++i < len - 1)
	{
		j = i;
		while (++j <= len)
		{
			if (tab[i] > tab[j])
				return (0);
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:53:38 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/08 15:53:40 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabndup(int *tab, int n, int len)
{
	int		*new;
	int		size;
	int		i;

	i = 0;
	size = (len >= n) ? (n + 1) : (len + 1);
	if (!(new = (int*)ft_memalloc(sizeof(int) * size)))
		return (NULL);
	while (i <= len && i < n)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}

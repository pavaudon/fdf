/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:37:55 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/21 12:37:57 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_flen(double n)
{
	int		size;
	int		dec;

	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	dec = (int)n;
	while (dec)
	{
		dec /= 10;
		size++;
	}
	size += 7;
	return (size);
}

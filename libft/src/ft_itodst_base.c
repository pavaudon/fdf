/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itodst_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:26:45 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/17 18:26:47 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sign(long *nb)
{
	if (*nb < 0)
	{
		*nb = -(*nb);
		return (1);
	}
	return (0);
}

char			*ft_itodst_base(int n, char *dst, int base)
{
	int		len;
	long	nb;

	nb = n;
	len = ft_nb_len(nb, base);
	if (sign(&nb))
		dst[0] = '-';
	while (len--)
	{
		if ((nb % base) >= 10)
			dst[len] = (nb % base) - 10 + 'A';
		else
			dst[len] = nb % base + '0';
		nb /= base;
	}
	return (dst);
}

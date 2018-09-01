/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:20:17 by pavaudon          #+#    #+#             */
/*   Updated: 2018/01/18 18:20:18 by pavaudon         ###   ########.fr       */
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

char			*ft_itoa_base(int n, int base)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_nb_len(nb, base);
	if (!(str = (char*)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	if (sign(&nb))
		str[0] = '-';
	while (len--)
	{
		if ((nb % base) >= 10)
			str[len] = (nb % base) - 10 + 'A';
		else
			str[len] = nb % base + '0';
		nb /= base;
	}
	return (str);
}

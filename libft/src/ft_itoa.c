/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:44:32 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/15 15:10:07 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sign(int *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (1);
	}
	return (0);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nb_len(n, 10);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (sign(&n))
		str[0] = '-';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

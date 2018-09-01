/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:37:23 by pavaudon          #+#    #+#             */
/*   Updated: 2018/04/27 17:37:25 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sign(long long *nb)
{
	if (*nb < 0)
	{
		*nb = -(*nb);
		return (1);
	}
	return (0);
}

char			*ft_lltoa_base(long long n, int base)
{
	char	*str;
	int		len;

	len = ft_ll_base_len(n, base);
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	if (sign(&n))
		str[0] = '-';
	while (len--)
	{
		if ((n % base) >= 10)
			str[len] = (n % base) - 10 + 'A';
		else
			str[len] = (str[len] == '-') ? str[len] : n % base + '0';
		n = n / base;
	}
	return (str);
}

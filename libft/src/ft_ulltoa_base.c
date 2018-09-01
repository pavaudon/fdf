/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:42:51 by pavaudon          #+#    #+#             */
/*   Updated: 2018/04/27 17:42:53 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	char		*str;
	int			len;

	len = ft_ull_base_len(n, base);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		if ((n % base) >= 10)
			str[len] = (n % base) - 10 + 'A';
		else
			str[len] = n % base + '0';
		n = n / base;
	}
	return (str);
}

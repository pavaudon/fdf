/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:36:28 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/21 12:36:32 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ftoa(double n)
{
	int			size;
	int			i;
	int			point;
	char		*str;

	size = ft_flen(n);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_lltodst_base((long long)n, str, 10);
	point = ft_ll_base_len((long long)n, 10);
	n *= n < 0 ? -1 : 1;
	n = n - (long long)n;
	i = 0;
	while (i < 6)
	{
		n = (n * 10) + 0.0000001;
		i++;
	}
	str[point++] = '.';
	ft_lltodst_base((long long)n, (str + point), 10);
	return (str);
}

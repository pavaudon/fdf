/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:08:26 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/16 14:37:29 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s;
	unsigned char	tmp_c;

	tmp_c = (unsigned char)c;
	tmp_s = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == tmp_c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}

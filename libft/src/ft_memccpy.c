/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:31:14 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/16 14:34:39 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	unsigned char	tmp_c;

	i = 0;
	tmp_src = (unsigned char*)src;
	tmp_dst = (unsigned char*)dst;
	tmp_c = (unsigned char)c;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_src[i] == tmp_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

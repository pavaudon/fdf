/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:24:58 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/14 17:17:11 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	while (dest[i] && i < size)
		i++;
	len = i;
	while (src[i - len] && i < size - 1)
	{
		dest[i] = src[i - len];
		i++;
	}
	if (len < size)
		dest[i] = '\0';
	return (len + ft_strlen(src));
}

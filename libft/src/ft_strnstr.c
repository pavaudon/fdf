/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:33:35 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/16 14:23:57 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(needle[i]))
		return ((char*)haystack);
	while (haystack[j] && j < len)
	{
		while (haystack[j] && haystack[i + j] == needle[i] && (j + i) < len)
		{
			i++;
			if (!(needle[i]))
				return ((char*)haystack + j);
		}
		i = 0;
		j++;
	}
	return (NULL);
}

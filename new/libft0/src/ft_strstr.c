/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:11:06 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/14 13:59:27 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(needle[i]))
		return ((char*)haystack);
	while (haystack[j])
	{
		while (haystack[i + j] == needle[i])
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoinset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:02:05 by pavaudon          #+#    #+#             */
/*   Updated: 2018/04/06 15:02:24 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoinset(char *str, char c, int len, int where)
{
	char	*dest;
	int		size;
	int		i;

	size = ft_strlen(str) + len;
	i = (!where) ? 0 : ft_strlen(str);
	if (!(dest = (char*)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (where)
	{
		ft_strcpy(dest, str);
		while (len--)
			dest[i++] = c;
		dest[i] = '\0';
	}
	else
	{
		while (len--)
			dest[i++] = c;
		dest[i] = '\0';
		ft_strcat(dest, str);
	}
	ft_strdel(&str);
	return (dest);
}

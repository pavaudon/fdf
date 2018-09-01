/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:15:04 by pavaudon          #+#    #+#             */
/*   Updated: 2018/05/02 13:15:05 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinc(char c, int len)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
		str[i] = c;
	str[i] = '\0';
	return (str);
}

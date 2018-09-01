/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:53:09 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/08 14:53:10 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char const *s1, char const *s2, char to_free)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (to_free == 'f' || to_free == 'b')
		ft_strdel((char**)(&s1));
	if (to_free == 's' || to_free == 'b')
		ft_strdel((char**)(&s2));
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfnjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:52:23 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/08 14:52:26 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfnjoin(const char *s1, const char *s2, int n, char to_free)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strncat(str, s2, n);
	if (to_free == 'f' || to_free == 'b')
		ft_strdel((char**)(&s1));
	if (to_free == 's' || to_free == 'b')
		ft_strdel((char**)(&s2));
	return (str);
}

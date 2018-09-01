/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:46:54 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/13 18:02:23 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	i = 0;
	tmp_s = (char*)s;
	while (tmp_s[i])
	{
		if (tmp_s[i] == c)
			return (&tmp_s[i]);
		i++;
	}
	if (tmp_s[i] == c)
		return (&tmp_s[i]);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:53:48 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/13 18:03:49 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	tmp_s = (char*)s;
	i = 0;
	while (tmp_s[i])
		i++;
	while (i >= 0)
	{
		if (tmp_s[i] == c)
			return (&tmp_s[i]);
		i--;
	}
	return (NULL);
}

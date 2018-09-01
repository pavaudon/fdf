/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:09:01 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/15 16:26:31 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s)
{
	size_t i;
	size_t end;

	i = 0;
	end = 0;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
	{
		i++;
		end++;
		if (end == ft_strlen(s))
			return (0);
	}
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
	{
		i++;
		end--;
	}
	return (ft_strlen(s) - i);
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	len = ft_len((char*)s);
	i = 0;
	j = 0;
	if (!len || !*s)
		return (ft_strnew(1));
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < len)
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

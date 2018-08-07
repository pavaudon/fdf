/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:18:59 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/17 18:48:52 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tab_len(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			len++;
		}
	}
	return (len);
}

static int	word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		index;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	index = 0;
	len = tab_len(s, c);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * len + 1)))
		return (NULL);
	while (index < len)
	{
		while (s[i] == c && s[i])
			i++;
		tab[index] = ft_strsub(s, i, word_len(&s[i], c));
		i = i + word_len(&s[i], c);
		index++;
	}
	tab[index] = NULL;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:11:41 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/14 17:11:48 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char*)s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}

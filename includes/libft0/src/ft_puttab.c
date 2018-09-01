/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:44:18 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/09 16:44:20 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(int *tab, int len)
{
	int i;

	i = -1;
	if (len == 0)
	{
		ft_putstr(">>	");
		ft_putstr("EMPTY");
		ft_putstr("	<<\n");
		return ;
	}
	while (++i < len)
	{
		ft_putstr(">>	");
		ft_putnbr(tab[i]);
		ft_putstr("	<<");
		ft_putchar('\n');
	}
}

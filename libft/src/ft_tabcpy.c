/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:02:41 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 20:02:43 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabcpy(int *tab, int *to_cpy, int len)
{
	int i;

	i = -1;
	while (++i <= len)
		to_cpy[i] = tab[i];
	return (to_cpy);
}

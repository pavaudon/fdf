/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_incharset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:03:15 by pavaudon          #+#    #+#             */
/*   Updated: 2018/05/11 19:03:16 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_incharset(char c, char *charset)
{
	size_t	idx;

	idx = 0;
	while (charset[idx] && !(c == charset[idx]))
		idx++;
	return (!!charset[idx]);
}

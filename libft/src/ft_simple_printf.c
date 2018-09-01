/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:15:28 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/02 12:15:30 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_simple_printf(const char *format, ...)
{
	va_list ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if (format[i + 1] == 'd')
				ft_putnbr(va_arg(ap, int));
			else if (format[i + 1] == 's')
				ft_putstr(va_arg(ap, char*));
			else if (format[i + 1] == 'c')
				ft_putchar(va_arg(ap, int));
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

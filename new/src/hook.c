/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:21:13 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/31 16:21:14 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int windows_exit()
{
	ft_simple_printf("Bybye\n");
	exit(0);
	return (0);
}

int		ft_key(int key, t_data *data)
{
	if (key == 53)
	{
		ft_simple_printf("esc\n");
		exit(0);
	}
	else if (key == 37 && data->data_img)		//l
	{
		put_text(data);
		tracer_line(data);
	}
	else if (key == 126 || key == 69) //haut
		data->zoom++;
	else if ((key == 125 || key == 78) && data->zoom > 1) // bas
  	data->zoom--;
	else
		ft_simple_printf("key is : %d \n", key);
	return (0);
}

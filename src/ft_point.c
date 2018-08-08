/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:09:41 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/08 16:09:44 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_new_image(t_data *data)
{
	int		x;
	int		y;
	t_list	*tmp;

	y = -1;
	tmp = data->list;
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_max, data->y_max);
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max)
		{
			while (tmp->next)
			{
				if (tmp->y == y && tmp->x == x)
					machin = 25250; //couleur random 98|2|34
				else
					machin = 174762; //couleur random 42|42|42
				tmp = tmp->next;
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

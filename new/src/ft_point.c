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
	int	x;
	int y;

	y = -1;
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_max, data->y_max);
	data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
	ft_simple_printf("bpp : '%d'\nsl : '%d'\n", data->bpp, data->sl);
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max)
		{
			ft_simple_printf("x : %d\ty : %d\tz : %d\n", x, y, data->tab[y][x]);
			if (data->tab[y][x] == 0)
			{
				//ft_simple_printf("data->tab[%d][%d]\n", y, x);
				*(unsigned int*)(data->data_img + ((x) * (data->bpp)) + (y * data->sl)) = 0x00FF00;
			}
			else
				*(unsigned int*)(data->data_img + ((x) * (data->bpp)) + ((y - data->tab[y][x]) * (data->sl))) = 0xFF0200;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 50, 50);
}

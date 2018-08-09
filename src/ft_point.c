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
	data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl, &data->ed);
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max)
		{
			if (data->tab[y][x] != 0)
				*(unsigned int*)(data->data_img + (x * (data->bpp * 5)) +
				((y - data->tab[y][x]) * data->sl)) = 0x007D76;			//test bpp * 5
			else
				*(unsigned int*)(data->data_img + (x * (data->bpp * 5)) +
				(y * data->sl)) = 0xE92476;								//test bpp *5
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

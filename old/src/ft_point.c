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

void		put_text(t_data *data)
{
	if (!data->img_ptr)
	{
		data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
		data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
		&data->ed);
	}
	//mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 900, 0x23a790, "U to unicorn\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 925, 0xFFC9C9, "P to draw points\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 950, 0xFFC9C9, "L to draw lines\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 975, 0xFFC9C9, "ESC or CROSS to quit\n");
}

void		ft_new_image(t_data *data)
{
	int	x;
	int y;

	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_allmax, data->y_max);
	data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
	y = data->nb_y;
	//printf("y : '%d' nb_y : '%d'\n", data->y_max, data->nb_y);
	while (y--)
	{
		x = data->x_max[y];
		while (x--)
		{
			((unsigned int *)data->data_img)[(x * data->zoom) + ((y * data->zoom) * data->x_allmax)] =
			(data->tab[y][x] == 0) ? 0x00FF00 :
			(0xff0000 + (0x0000A8 * data->tab[y][x]));
			/*
			 if (data->tab[y][x] == 0)
			 {
			 	printf("data->tab[%d][%d] : %d\n", y, x, data->tab[y][x]);
			 	*(unsigned int*)(data->data_img + ((x) * (data->bpp >> 4)) + (y * data->sl)) = 0x00FF00;
			 }
			 else
			 {
			 	printf("x : %d\ty : %d\tz : %d\n", x, y, data->tab[y][x]);
			 	*(unsigned int*)(data->data_img + ((x) * (data->bpp >> 4)) + ((y - data->tab[y][x]) * (data->sl))) = 0xFF0200;
			 }
			 */
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 50, 50);
}

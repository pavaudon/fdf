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
/*
static void	ft_fillit(unsigned int *pixels, const unsigned int w,
	const unsigned int h, const unsigned int color)
{
	unsigned int		x;
	unsigned int		y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			pixels[x + y * w] = color;
		}
	}
}
*/

void		ft_new_image(t_data *data)
{
	int	x;
	int y;

	y = -1;
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
	//ft_simple_printf("x_max : '%d'\ny_max : %d\n", data->x_max, data->y_max);
	//ft_simple_printf("bpp : '%d'\nsl : '%d'\n", data->bpp, data->sl);
	y = data->y_max;
	while (y--)
	{
		//ft_simple_printf("x : %d\ty : %d\tz : %d\n", x, y, data->tab[y][x]);
		x = data->x_max[y];
		while (x--)
		{
			//ft_simple_printf("x : %d\ty : %d\tz : %d\n", x, y, data->tab[y][x]);
			((unsigned int *)data->data_img)[x + (y * 1000)] =
			(data->tab[y][x] == 0) ? 0x00FF00 :
			(0xff0000 + (0x0000A8 * data->tab[y][x]));
			//if (data->tab[y][x] == 0)
			//	((unsigned int *)data->data_img)[x + y * (data->x_max - 1)] = 0x00FF00;
			//else
			//	((unsigned int *)data->data_img)[x + (y - data->tab[y][x]) * (data->x_max - 1)] = 0xff0000;
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

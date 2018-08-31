/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:18:17 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/20 15:18:18 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_pixel(t_data *data, int x, int y)
{
	if (x >= 0 && x < data->x_allmax && y >= 0 && y < data->y_max)
			((unsigned int *)data->data_img)[x + y] = data->color;
}

int		ft_abs(int value)
{
	return ((value < 0) ? -value : value);
}

void	line_down(t_data *data, int x, int y)
{
	data->bres->error = data->bres->dx / 2;
	while (++x < data->bres->dx)
	{
		x += data->bres->xincr;
		data->bres->error += data->bres->dy;
		if (data->bres->error > data->bres->dx)
		{
			data->bres->error -= data->bres->dx;
			y += data->bres->yincr;
		}
		 ((unsigned int *)data->data_img)[(x) + ((y) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 : (0xff0000 + (0x0000A8 * data->tab[y][x]));
	}
}

void	line_up(t_data *data, int x, int y)
{
	data->bres->error = data->bres->dy / 2;
	while (++y < data->bres->dy)
	{
		y += data->bres->yincr;
		data->bres->error += data->bres->dx;
		if (data->bres->error > data->bres->dy)
		{
			data->bres->error -= data->bres->dy;
			x += data->bres->xincr;
		}
		((unsigned int *)data->data_img)[(x) + ((y) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 :(0xff0000 + (0x0000A8 * data->tab[y][x]));
	}
}

void	ft_bres(t_data *data, int x1, int y1, int x2, int y2)  // Bresenham
{
	int x;
	int	y;

	x1 *= data->zoom;
	y1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	x = x1;
	y = y1;
	data->bres->dx = ft_abs(x2 - x1);
	data->bres->dy = ft_abs(y2 - y1);
	data->bres->xincr = (x1 < x2) ? 1 : -1;
	data->bres->yincr = (y1 < y2) ? 1 : -1;
	//printf("POUR [X1 = '%d'][Y1 = '%d'][X2 = '%d'][Y2 = '%d']\nyincr : '%d'\tdy : '%d'\tdx : '%d'\n\n", x1, y1, x2, y2, data->bres->yincr, data->bres->dy, data->bres->dx);
	if (data->bres->dx > data->bres->dy)
		line_down(data, x, y);
	else
		line_up(data, x, y);
	 ((unsigned int *)data->data_img)[(x1) + ((y1) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 : (0xff0000 + (0x0000A8 * data->tab[y][x]));
	//((unsigned int *)data->data_img)[(x2) + ((y2) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 : (0xff0000 + (0x0000A8 * data->tab[y][x]));; normalement c'est gerer avec l'algo a voir avec tous les cas
}

void		tracer_line(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
	printf("nb_y : %d\t", data->nb_y);
	while (++y < data->nb_y)
	{
		x = -1;
		while (++x < data->x_max[y])
		{
			printf("x_max : '%d'\n", data->x_max[y]);
			if (y < data->nb_y - 1)
				ft_bres(data, x, y - data->tab[y][x], x, (y + 1) - data->tab[y + 1][x]);
			if (x < data->x_max[y] - 1)
				ft_bres(data, x, y - data->tab[y][x], (x + 1), y - data->tab[y][x + 1]);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 50, 50);
}

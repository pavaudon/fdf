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

void		tracer_line(t_data *data)
{
	int		y;
	int		x;
	t_bres *bres;

	y = 0;
	if (!(bres = (t_bres*)ft_memalloc(sizeof(t_bres))))
		return (0);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_allmax, data->y_max);
	data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
	while (y++ < data->nb_y)
	{
		x = 0;
		while (x++ < data->x_max[y])
		{
			if (y)
				ft_bres(bres, x, y * data->tab[y][x], x, (y - 1) * data->tab[y - 1][x]);
			if (x)
				ft_bres(bres, x, y * data->tab[y][x], x - 1, y * data->tab[y][x - 1]);
			if (y < data->nb_y - 1)
				ft_bres(bres, x, y * data->tab[y][x], x, (y + 1) * data->tab[y + 1][x];
			if (x < data->x_max[y] - 1)
				ft_bres(bres, x, y * data->tab[y][x], x + 1, y * data->tab[y][x + 1]);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 50, 50)
}

int		ft_abs(int value)
{
	return ((value < 0) ? -value : value);
}

void	line_down(t_bres *bres, int x, int y)
{
	data->error = data->dx / 2;
	while (++x < data->dx)
	{
		x += data->xincr;
		data->error += data->dy;
		if (data->error > data->dx)
		{
			data->error -= data->dx;
			y += data->yincr;
		}
		((unsigned int *)data->data_img)[(x * data->zoom) + ((y * data->zoom) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 :
		(0xff0000 + (0x0000A8 * data->tab[y][x]));;
	}
}

void	line_up(t_bres *bres, int x, int y)
{
	data->error = data->dy / 2;
	while (++y < data->dy)
	{
		y += data->yincr;
		data->error += data->dx;
		if (data->error > data->dy)
		{
			data->error -= data->dy;
			x += data->xincr;
		}
		((unsigned int *)data->data_img)[(x * data->zoom) + ((y * data->zoom) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 :
		(0xff0000 + (0x0000A8 * data->tab[y][x]));;
	}
}

void	ft_bres(t_data *bres, int x1, int y1, int x2, int y2)  // Bresenham
{
	int x;
	int	y;

	data->dx = ft_abs(x2 - x1);
	data->dy = ft_abs(y2 - y1);
	data->xincr = (x1 < x2) ? 1 : -1;
	data->yincr = (y1 < y2) ? 1 : -1;
	x = x1;
	y = y1;
	if (data->dx > data->dy)
		line_down(bres, x, y);
	else
		line_up(bres, x, y);
	((unsigned int *)data->data_img)[(x1 * data->zoom) + ((y1 * data->zoom) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 :
	(0xff0000 + (0x0000A8 * data->tab[y][x]));;
	//((unsigned int *)data->data_img)[(x2 * data->zoom) + ((y2 * data->zoom) * data->x_allmax)] = (data->tab[y][x] == 0) ? 0x00FF00 : (0xff0000 + (0x0000A8 * data->tab[y][x]));; normalement c'est gerer avec l'algo a voir avec tous les cas
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:09 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/13 12:01:43 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	return ((value < 0) ? -value : value);
}

void	line_down(t_data *data, int x, int y)
{
	int i;

	i = -1;
	data->bres->error = data->bres->dx / 2;
	while (++i < data->bres->dx)
	{
		x += data->bres->xincr;
		data->bres->error += (double)data->bres->dy;
		if (data->bres->error >= (double)data->bres->dx)
		{
			data->bres->error -= (double)data->bres->dx;
			y += data->bres->yincr;
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->xmove, y +
				data->ymove, 0xe6ea07);
	}
}

void	line_up(t_data *data, int x, int y)
{
	int i;

	i = -1;
	data->bres->error = data->bres->dy / 2;
	while (++i < data->bres->dy)
	{
		y += data->bres->yincr;
		data->bres->error += (double)data->bres->dx;
		if (data->bres->error > (double)data->bres->dy)
		{
			data->bres->error -= data->bres->dy;
			x += data->bres->xincr;
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->xmove, y +
				data->ymove, 0xe6ea07);
	}
}

void	set_zoom(t_data *data, int *x, int *y)
{
	data->bres->x1 *= data->zoom;
	data->bres->y1 *= data->zoom;
	*x *= data->zoom;
	*y *= data->zoom;
}

void	ft_bres(t_data *data, int x2, int y2)
{
	set_zoom(data, &x2, &y2);
	data->bres->dx = ft_abs(x2 - data->bres->x1);
	data->bres->dy = ft_abs(y2 - data->bres->y1);
	data->bres->xincr = (data->bres->x1 < x2) ? 1 : -1;
	data->bres->yincr = (data->bres->y1 < y2) ? 1 : -1;
	if (data->bres->dx > data->bres->dy)
		line_down(data, data->bres->x1, data->bres->y1);
	else
		line_up(data, data->bres->x1, data->bres->y1);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->bres->x1 + data->xmove,
			data->bres->y1 + data->ymove, 0xe6ea07);
}

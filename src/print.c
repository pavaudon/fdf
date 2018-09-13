/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:31:42 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/13 12:10:56 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_text(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 825, 0xFFC9C9,
			"L to draw lines\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 850, 0xFFC9C9,
			"+ (num pad) to zoom+\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 875, 0xFFC9C9,
			"- (num pad) to zoom-\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 900, 0xFFC9C9,
			"UP DOWN LEFT OR RIGHT to move\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 925, 0xFFC9C9,
			"+ to depth+\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 950, 0xFFC9C9,
			"- to depth-\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 975, 0xFFC9C9,
			"ESC or CROSS to quit\n");
}

void	change_depth(t_data *data)
{
	int y;
	int x;
	int zero;

	y = -1;
	zero = 0;
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max[y])
		{
			if (data->tab[y][x] == 1 && data->depth == -1)
				zero--;
			if (data->tab[y][x] == -1 && data->depth == 1)
				zero++;
			if (data->tab[y][x] != 0)
				data->tab[y][x] += data->depth + zero;
			zero = 0;
		}
	}
}

void	draw_point(t_data *data)
{
	int x;
	int y;
	int color;

	y = -1;
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max[y])
		{
			color = (data->tab[y][x] == 0) ? 0x00FF00 :
				(0xff0000 + (0x0000A8 * data->tab[y][x]));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x * data->zoom +
			data->xmove, y * data->zoom + data->ymove, color);
		}
	}
}

void	draw_lines(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max[y])
		{
			if (y < data->y_max - 1 && x < data->x_max[y + 1])
			{
				data->bres->x1 = x + y;
				data->bres->y1 = y - data->tab[y][x];
				ft_bres(data, (x + y + 1), (y + 1) - data->tab[y + 1][x]);
			}
			if (x < data->x_max[y] - 1)
			{
				data->bres->x1 = x + y;
				data->bres->y1 = y - data->tab[y][x];
				ft_bres(data, (x + y + 1), y - data->tab[y][x + 1]);
			}
		}
	}
}

void	which_draw(t_data *data, int lines)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (!lines)
		change_depth(data);
	if (lines < 2)
		draw_lines(data);
	else if (lines == 2)
		draw_point(data);
	put_text(data);
}

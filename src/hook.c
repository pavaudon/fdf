/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:21:13 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/13 12:20:42 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		windows_exit(void)
{
	ft_simple_printf("Bybye\n");
	exit(0);
	return (0);
}

void	ft_depth_zoom(int key, t_data *data)
{
	if (key == 69)
	{
		data->zoom++;
		which_draw(data, 1);
	}
	else if (key == 78 && data->zoom > 1)
	{
		data->zoom--;
		which_draw(data, 1);
	}
	else if (key == 24)
	{
		data->depth = 1;
		which_draw(data, 0);
	}
	else if (key == 27)
	{
		data->depth = -1;
		which_draw(data, 0);
	}
}

void	ft_move(int key, t_data *data)
{
	if (key == 124)
	{
		data->xmove += (data->xmove < LINE_SIZE) ? 10 : 0;
		which_draw(data, 1);
	}
	else if (key == 123)
	{
		data->xmove -= (data->xmove > 1) ? 10 : 0;
		which_draw(data, 1);
	}
	else if (key == 125)
	{
		data->ymove += (data->ymove < COL_SIZE) ? 10 : 0;
		which_draw(data, 1);
	}
	else if (key == 126)
	{
		data->ymove -= (data->ymove > 1) ? 10 : 0;
		which_draw(data, 1);
	}
}

int		ft_key(int key, t_data *data)
{
	if (key == 53)
	{
		ft_simple_printf("esc\n");
		exit(0);
	}
	else if (key == 37 && data->data_img)
		which_draw(data, 1);
	else if (key == 35 && data->data_img)
		which_draw(data, 2);
	else if (key == 69 || key == 78 || key == 24 || key == 27)
		ft_depth_zoom(key, data);
	else if (key >= 124 && key <= 126)
		ft_move(key, data);
	return (0);
}

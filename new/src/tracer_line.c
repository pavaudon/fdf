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
	int y;
	int x;
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);


	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0)
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:31:42 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/31 16:31:43 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_text(t_data *data)
{
  mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 900, 0xFFC9C9, "L to draw lines\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 925, 0xFFC9C9, "+ or UP to zoom+\n");
  mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 950, 0xFFC9C9, "- or DOWN to zoom-\n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 975, 0xFFC9C9, "ESC or CROSS to quit\n");
}

void put_background(t_data *data)
{
  int x;
  int y;

  y = -1;
  while (++y <= 1000)
  {
    x = -1;
    while (++x <= 1000)
    {
      *(unsigned int*)(data->data_img + ((x) * (data->bpp >> 4)) + (y * data->sl)) = 0x3d3e47;
    }
  }
  put_text(data);
  draw_lines(data);
}

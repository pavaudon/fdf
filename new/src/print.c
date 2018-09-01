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

void print_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
	 //((unsigned int *)data->data_img)[x + y] = color;
   *(unsigned int*)(data->data_img + (x * (data->bpp >> 4)) + (y * data->sl)) = color;
}

void draw_point(t_data *data)
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
      print_pixel(data, x * data->zoom, y * data->zoom, color);
    /*  ((unsigned int *)data->data_img)[(x * data->zoom) + ((y * data->zoom) * data->x_allmax)] =
			(data->tab[y][x] == 0) ? 0x00FF00 :
			(0xff0000 + (0x0000A8 * data->tab[y][x]));*/
    }
  }
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 50, 50);
}

void draw_lines(t_data *data)
{
  int x;
  int y;

  y = -1;
  while (++y < data->y_max)
  {
    x = -1;
    while (++x < data->x_max[y])
    {
      if (y < data->y_max - 1)
				ft_bres(data, x, y - data->tab[y][x], x, (y + 1) - data->tab[y + 1][x]);
			if (x < data->x_max[y] - 1)
				ft_bres(data, x, y - data->tab[y][x], (x + 1), y - data->tab[y][x + 1]);
    }
  }
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 50, 50);
}


void put_background(t_data *data, int lines)
{
  int x;
  int y;

  y = -1;
  data->img_ptr = mlx_new_image(data->mlx_ptr, COL_SIZE, LINE_SIZE);
  data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
  while (++y <= LINE_SIZE)
  {
    x = -1;
    while (++x <= COL_SIZE)
      print_pixel(data, x, y, 0x3d3e47);
  }
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
  put_text(data);
  if (lines == 1)
    draw_lines(data);
  else if (lines == 2)
    draw_point(data);
}
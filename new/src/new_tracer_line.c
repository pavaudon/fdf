/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tracer_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 15:39:37 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/26 15:39:40 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_abs(int value)
{
  return ((value < 0) ? -value : value);
}

void line_down(t_data *data, int x, int y)
{
  int i;

  i = -1;
  //printf("\nLINE_DOWN\n");
  data->bres->error = data->bres->dx / 2;
  while (++i < data->bres->dx)
  {
    x += data->bres->xincr;
    data->bres->error += data->bres->dy;
    if (data->bres->error > data->bres->dx)
    {
      data->bres->error -= data->bres->dx;
      y += data->bres->yincr;
    }
    printf("put x : '%d'\ty : '%d'\n", x / data->zoom, y / data->zoom);
    *(unsigned int*)(data->data_img + ((x) * (data->bpp >> 4)) + (y * data->sl)) = 0x00FF00;
  }
}

void line_up(t_data *data, int x, int y)
{
  int i;

  i = -1;
  printf("\nLINE_UP\n");
  data->bres->error = data->bres->dy / 2;
  while (++i < data->bres->error)
  {
    y += data->bres->yincr;
    data->bres->error += data->bres->dx;
    if (data->bres->error > data->bres->dy)
    {
      data->bres->error -= data->bres->dy;
      x += data->bres->xincr;
    }
  //  printf("put x : '%d'\ty : '%d'\n");
  *(unsigned int*)(data->data_img + ((x) * (data->bpp >> 4)) + (y * data->sl)) = 0x00FF00;
  }
}

void ft_bres(t_data *data, int x1, int y1, int x2, int y2)
{
  printf("\nx1 : '%d'\ty1 :'%d'\tx2 : '%d'\ty2 : '%d'\n", x1, y1, x2, y2);
  x1 *= data->zoom;
  x2 *= data->zoom;
  y1 *= data->zoom;
  y2 *= data->zoom;
  data->bres->dx = ft_abs(x2 - x1);
  data->bres->dy = ft_abs(y2 - y1);
  printf("dx : '%d'\tdy : '%d'\n", data->bres->dx, data->bres->dy);
  data->bres->xincr = (x1 < x2) ? 1 : -1;
  data->bres->yincr = (y1 < y2) ? 1 : -1;
  if (data->bres->dx > data->bres->dy)
    line_down(data, x1, y1);
  else
    line_up(data, x1, y1);
  *(unsigned int*)(data->data_img + ((x1) * (data->bpp >> 4)) + (y1 * data->sl)) = 0x00FF00;
}

void tracer_line(t_data *data)
{
  int x;
  int y;

  y = -1;
  data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
  while (++y < data->nb_y)
  {
    x = -1;
    while (++x < data->x_max[y])
    {
      if (x < data->x_max[y] - 1)
      {
        printf("TAMERE\n");
        ft_bres(data, x, y - data->tab[y][x], x + 1, y - data->tab[y][x + 1]);
      }
      if (y < data->nb_y - 1)
        ft_bres(data, x , y - data->tab[y][x], x, (y + 1) - data->tab[y + 1][x]);
    }
  }
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 50, 50);
}

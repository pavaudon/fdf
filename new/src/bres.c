/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:09 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/01 14:27:11 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int  ft_abs(int value)
{
  return ((value < 0) ? -value : value);
}

void line_down(t_data *data, int x, int y)
{
  int i;
  int color;

  i = -1;
  color = 0xe6ea07;
  data->bres->error = (double)data->bres->dx / 2;
  while (++i < data->bres->dx)
  {
    x += data->bres->xincr;
    data->bres->error += (double)data->bres->dy;
    if (data->bres->error > (double)data->bres->dx)
    {
      data->bres->error -= (double)data->bres->dx;
      y += data->bres->yincr;
      //color += (i) ? 0x5103b7 : 0;
    }
    print_pixel(data, x, y, color);
  }
}

void line_up(t_data *data, int x, int y)
{
  int i;

  i = -1;
  data->bres->error = (double)data->bres->dy / 2;
  while (++i < data->bres->dy)
  {
    y += data->bres->yincr;
    data->bres->error += (double)data->bres->dx;
    if (data->bres->error > (double)data->bres->dy)
    {
      data->bres->error -= data->bres->dy;
      x += data->bres->xincr;
    }
    print_pixel(data, x, y, 0xe6ea07);
  }

}

void ft_bres(t_data *data, int x1, int y1, int x2, int y2)
{
  x1 *= data->zoom;
	y1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
  data->bres->dx = ft_abs(x2 - x1);
  data->bres->dy = ft_abs(y2 - y1);
  data->bres->xincr = (x1 < x2) ? 1 : -1;
  data->bres->yincr = (y1 < y2) ? 1 : -1;
  if (data->bres->dx > data->bres->dy)
    line_down(data, x1, y1);
  else
    line_up(data, x1, y1);
  print_pixel(data, x1, y1, 0xe6ea07);
}

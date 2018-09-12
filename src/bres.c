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
/*
void line_down(t_data *data, int x, int y)
{
  int i;
  int inc_1;
  int inc_2;
  //int color;

  i = -1;
  //color = 0xe6ea07;
  printf("LINEDOWN\n");
  data->bres->error = 2 * data->bres->dy - data->bres->dx;
  printf("dx : '%d'\tdy : '%d'\t error : '%f'\n", data->bres->dx, data->bres->dy, data->bres->error);
  inc_1 = 2 * (data->bres->dy - data->bres->dx);
  inc_2 = 2 * data->bres->dy;
  printf("INC_1 : '%d'\tINC_2 : '%d'\n\n", inc_1, inc_2);
  while (++i < data->bres->dx)
  {
    if (data->bres->error <= 0)
    {
      y += data->bres->yincr;
      data->bres->error += inc_1;
    }
    else
      data->bres->error += inc_2;
    x += data->bres->xincr;
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xe6ea07);
  }
}
*/

void line_down(t_data *data, int x, int y)
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
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->xmove, y + data->ymove, 0xe6ea07);
  }
}

/*
void line_up(t_data *data, int x, int y)
{
  int i;
  int inc_1;
  int inc_2;

  i = -1;
  printf("LINEUP\n");
  data->bres->error = 2 * data->bres->dx - data->bres->dy;
  printf("dx : '%d'\tdy : '%d'\t error : '%f'\n", data->bres->dx, data->bres->dy, data->bres->error);
  inc_1 = 2 * (data->bres->dx - data->bres->dy);
  inc_2 = 2 * data->bres->dx;
  printf("INC_1 : '%d'\tINC_2 : '%d'\n\n", inc_1, inc_2);
  while (++i < data->bres->dy)
  {
    if (data->bres->error >= 0)
    {
      x += data->bres->xincr;
      data->bres->error += inc_1;
    }
    else
      data->bres->error += inc_2;
    y += data->bres->yincr;
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xe6ea07);
  }
}
*/

void line_up(t_data *data, int x, int y)
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
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->xmove, y + data->ymove, 0xe6ea07);
  }
}

void set_var(t_data *data, int *x1, int *y1, int *x2, int *y2)
{
  *x1 *= data->zoom;
  *y1 *= data->zoom;
  *x2 *= data->zoom;
  *y2 *= data->zoom;
}

void ft_bres(t_data *data, int x1, int y1, int x2, int y2)
{
  //ft_simple_printf("\nBEFORE ZOOM\nx1 : '%d'\ty1 : '%d'\tx2 : '%d'\ty2 : '%d'\n", x1, y1, x2, y2);
  set_var(data, &x1, &y1, &x2, &y2);
  //ft_simple_printf("AFTER ZOOM\nx1 : '%d'\ty1 : '%d'\tx2 : '%d'\ty2 : '%d'\n", x1, y1, x2, y2);
  data->bres->dx = ft_abs(x2 - x1);
  data->bres->dy = ft_abs(y2 - y1);
  data->bres->xincr = (x1 < x2) ? 1 : -1;
  data->bres->yincr = (y1 < y2) ? 1 : -1;
  if (data->bres->dx > data->bres->dy)
    line_down(data, x1, y1);
  else
    line_up(data, x1, y1);
  mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1 + data->xmove, y1 + data->ymove, 0xe6ea07);
}

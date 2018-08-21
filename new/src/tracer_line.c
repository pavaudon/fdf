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

void Line(SDL_Surface* surf, int x1, int y1, int x2, int y2, int couleur)  // Bresenham
{
  int x,y;
  int Dx,Dy;
  int xincr,yincr;
  int erreur;
  int i;

  Dx = abs(x2-x1);
  Dy = abs(y2-y1);
  xincr = (x1 < x2) ? 1 : -1;
  yincr = (y1 < y2) ? 1 : -1;
  x = x1;
  y = y1;
  i = 0;
  if(Dx > Dy)
    {
      erreur = Dx / 2;
      while (i++ < Dx)
        {
          x += xincr;
          erreur += Dy;
          if(erreur > Dx)
        	{
              erreur -= Dx;
              y += yincr;
        	}
        putpixel(surf,x, y,couleur);
        }
    }
  else
    {
      erreur = Dy / 2;
      while (i++ < Dy)
        {
          y += yincr;
          erreur += Dx;
          if(erreur > Dy)
            {
              erreur -= Dy;
              x += xincr;
            }
        putpixel(surf, x, y, couleur);
        }
    }
    putpixel(surf, x1, y1, couleur);
    putpixel(surf, x2, y2, couleur);
}

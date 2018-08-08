/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:47:28 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/07 18:47:30 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "libft.h"

# define SIZE_X 250
# define SIZE_Y 250

typedef struct		s_point //chaque maillon == un point a tracer
{
	int				z;
	int				x;
	int				y;
	//int			color;
	struct s_point	*next;
	struct s_point	*prev;
}					t_point;

typedef struct		s_data
{
	t_point	*point;
	size_t	x_max;
	size_t	y_max;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int 	bpp;
	int 	sl;
	int 	ed;
	char 	*data_img;
}					t_data;

#endif

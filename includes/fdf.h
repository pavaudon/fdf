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
}					t_data;

#endif

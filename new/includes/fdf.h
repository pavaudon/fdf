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

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

typedef struct		s_bres
{
	int		xa;
	int		xb;
	int		ya;
	int		yb;
	int		dx;
	int		dy;
	int		xincr;
	int		yincr;
	double	error;
}					t_bres;

typedef struct    s_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data_img;
}                 t_mlx;

typedef struct    s_draw
{
  int     y_max;
  int     *x_max;
}                 t_draw

typedef struct		s_data
{
	//t_point	*point;
  t_mlx   *mlx;
	t_bres	*bres;
	int			**tab;
	char		*file;
	int			fd_1;
	int			fd_2;
	int			bpp;
	int			sl;
	int			ed;
	int			zoom;
}					t_data;

int			ft_read_file(t_data *data);
void		ft_new_image(t_data *data);
int			ft_parser_line(char *line, t_data *data, int y);
void		put_text(t_data *data);
void		tracer_line(t_data *data);
void		put_text(t_data *data);

#endif

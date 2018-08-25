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

/*
typedef struct		s_point //chaque maillon == un point a tracer
{
	int				z;
	int				x;
	int				y;
	//int			color;
	struct s_point	*next;
	struct s_point	*prev;
}					t_point;
*/

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
	float	error;
}					t_bres;

typedef struct		s_data
{
	//t_point	*point;
	t_bres	*bres;
	int			**tab;
	int			*x_max;
	int			x_allmax;
	int			nb_x;
	int			nb_y;
	int 		color;
	int			y_max;
	char		*file;
	int			fd_1;
	int			fd_2;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bpp;
	int			sl;
	int			ed;
	char		*data_img;
	int			zoom;
}					t_data;

int			ft_file_read(t_data *data);
void		ft_new_image(t_data *data);
int			ft_parser_line(char *line, t_data *data, int y);
void		put_text(t_data *data);
void		tracer_line(t_data *data);

#endif

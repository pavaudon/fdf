/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:47:28 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/13 19:35:35 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

# define COL_SIZE 1000
# define LINE_SIZE 1000

typedef struct		s_bres
{
	int			dx;
	int			dy;
	int			xincr;
	int			yincr;
	double		error;
	int			x1;
	int			y1;
}					t_bres;

typedef struct		s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*data_img;
	t_bres		*bres;
	int			**tab;
	char		*file;
	int			fd_1;
	int			fd_2;
	int			y_max;
	int			*x_max;
	int			zoom;
	int			depth;
	int			xmove;
	int			ymove;
}					t_data;

int					ft_read_file(t_data *data);
void				ft_new_image(t_data *data);
int					ft_parser_line(char *line, t_data *data, int y);
void				put_text(t_data *data);
void				tracer_line(t_data *data);
int					windows_exit(t_data *data);
int					ft_key(int key, t_data *data);
void				ft_bres(t_data *data, int x2, int y2);
void				which_draw(t_data *data, int lines);
void				ft_error(char *error, char *arg, t_data *data);
int					ft_init_data(t_data *data);
int					ft_init_mlx(t_data *data, char *argv);
void				ft_freetab(char **tab);
char				*del_path_file(char *file);

#endif

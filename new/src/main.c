/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:20:29 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/31 16:20:30 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_good_file(char *str)
{
	int		end;
	int		fdf;
	char	*tmp;

	fdf = 3;
	end = 0;
	tmp = ".fdf";
	if (ft_strlen(str) <= 5)
		return (0);
	while (str[end])
		end++;
	end--;
	while (fdf >= 0)
	{
		if (str[end] == tmp[fdf])
		{
			end--;
			fdf--;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_init_data(t_data *data)
{
	data->zoom = 1;
	data->tab = NULL;
	data->file = NULL;
	if (!(data->bres = (t_bres*)ft_memalloc(sizeof(t_bres))))
		return (0);
  if (!(data->mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
    return (0);
  data->mlx->mlx_ptr = NULL;
  data->mlx->win_ptr = NULL;
  data->mlx->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->mlx->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl,
	&data->ed);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data *data;

	if (!(data = (t_data*)ft_memalloc(sizeof(t_data))) || !ft_init_data(data))
		return (0);
	if (argc == 2)
	{
		if ((is_good_file(argv[1]) &&
		((data->fd_1 = open(argv[1], O_CLOEXEC)) > 0) &&
		(data->fd_2 = open(argv[1], O_CLOEXEC)) > 0) && ft_read_file(data))
		{
			data->file = argv[1];
			data->mlx_ptr = mlx_init();
			data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, argv[1]);
      draw_point(data);
			//mlx_hook(data->win_ptr, 2, (1L << 01), my_press_key, 0);
			//mlx_hook(data->win_ptr, 3, (1L << 01), my_remove_key, 0);
			mlx_key_hook(data->win_ptr, ft_key, data);
			mlx_hook(data->win_ptr, 17, 1L << 17, windows_exit, 0);
      put_background(data);
			mlx_loop(data->mlx_ptr);
		}
		else
			ft_simple_printf("bad file : '%s'\n", argv[1]);
	}
	else
		ft_simple_printf("no file\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:49:09 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/10 13:49:11 by pavaudon         ###   ########.fr       */
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

void	ft_zoom(t_data *data, int zoom)
{
	if (zoom) //haut
	{
		printf("BEFORE ZOOM++ :\ndata->x_allmax '%d'\ndata->y_max : '%d'\nzoom : '%d'\n", data->x_allmax, data->y_max, data->zoom);
		data->zoom++;
		data->x_allmax = data->nb_x * data->zoom;
		data->y_max = data->nb_y * data->zoom;
		printf("AFTER :\ndata->x_allmax '%d'\ndata->y_max : '%d'\nzoom : '%d'\n", data->x_allmax, data->y_max, data->zoom);
	}
	else // bas
	{
		printf("BEFORE ZOOM-- :\ndata->x_allmax '%d'\ndata->y_max : '%d'\nzoom : '%d'\n", data->x_allmax, data->y_max, data->zoom);
		data->zoom -= (data->zoom > 1) ? 1 : 0;
		data->x_allmax = data->nb_x * data->zoom;
		data->y_max = data->nb_y * data->zoom;
		printf("AFTER :\ndata->x_allmax '%d'\ndata->y_max : '%d'\nzoom : '%d'\n", data->x_allmax, data->y_max, data->zoom);
	}
}

int		ft_key(int key, t_data *data)
{
	if (key == 53)
	{
		ft_simple_printf("esc\n");
		exit(0);
	}
	else if (key == 37 && data->data_img)		//l
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_simple_printf("Empty line\n");
		put_text(data);
		tracer_line(data);
	}
	else if (key == 35)		//p
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_simple_printf("Empty points\n");
		put_text(data);
		ft_new_image(data);
	}
	else if (key == 126) //haut
		ft_zoom(data, 1);
	else if (key == 125) // bas
		ft_zoom(data, 0);
	else
		ft_simple_printf("key is : %d \n", key);
	return (0);
}
/*
int my_remove_key(int key)
{
	ft_simple_printf("result remove = %d \n", key);
	return (0);
}
*/
int windows_exit()
{
	ft_simple_printf("Bybye\n");
	exit(0);
	return (0);
}

int	ft_init_data(t_data *data)
{
	data->zoom = 1;
	data->tab = NULL;
	data->file = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->data_img = NULL;
	if (!(data->bres = (t_bres*)ft_memalloc(sizeof(t_bres))))
		return (0);
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
		(data->fd_2 = open(argv[1], O_CLOEXEC)) > 0) && ft_file_read(data))
		{
			data->file = argv[1];
			data->mlx_ptr = mlx_init();
			data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, argv[1]);
			put_text(data);
			//mlx_hook(data->win_ptr, 2, (1L << 01), my_press_key, 0);
			//mlx_hook(data->win_ptr, 3, (1L << 01), my_remove_key, 0);
			mlx_key_hook(data->win_ptr, ft_key, data);
			mlx_hook(data->win_ptr, 17, 1L << 17, windows_exit, 0);
			mlx_loop(data->mlx_ptr);
		}
		else
			ft_simple_printf("bad file : '%s'\n", argv[1]);
	}
	else
		ft_simple_printf("no file\n");
	return (0);
}

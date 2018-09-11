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

void ft_error(char *error, char *arg)
{
	if (arg)
		ft_simple_printf("BAD FILE [%s]\n", arg);
	else
		ft_simple_printf("%s\n", error);
	exit(1);
}

int check_file_name(char *arg)
{
	if (!ft_strstr(arg, ".fdf\0"))
		ft_error(NULL, arg);
	return (1);
}

char	*del_path_file(char *file)
{
	int i;
	int len;

	len = ft_strlen(file);
	i = len;
	while (--i)
	{
		if (file[i] == '/')
			return (ft_strdup(file + (i + 1)));
	}
	return (ft_strdup(file));
}

int	ft_init_data(t_data *data)
{
	data->zoom = 20;
	data->tab = NULL;
	data->file = NULL;
	if (!(data->bres = (t_bres*)ft_memalloc(sizeof(t_bres))))
		return (0);
	return (1);
}

int 	ft_init_mlx(t_data *data, char *argv)
{
	if (!(data->file = del_path_file(argv)))
		return (0);
	if (!(data->mlx_ptr = mlx_init()) ||
	!(data->win_ptr = mlx_new_window(data->mlx_ptr, COL_SIZE,
	LINE_SIZE, data->file)))
		return (0);
	free(data->file);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data *data;

	if (!(data = (t_data*)ft_memalloc(sizeof(t_data))) || !ft_init_data(data))
		return (0);
	if (argc == 2)
	{
		if ((check_file_name(argv[1]) &&
		((data->fd_1 = open(argv[1], O_CLOEXEC)) > 0) &&
		(data->fd_2 = open(argv[1], O_CLOEXEC)) > 0) && ft_read_file(data))
		{
			if (!ft_init_mlx(data, argv[1]))
				return (0);
			//mlx_hook(data->win_ptr, 2, (1L << 01), my_press_key, 0);		//mettre le zoom ici
			//mlx_hook(data->win_ptr, 3, (1L << 01), my_remove_key, 0);
			mlx_key_hook(data->win_ptr, ft_key, data);
			mlx_hook(data->win_ptr, 17, 1L << 17, windows_exit, 0);
      //put_background(data, 0);
			mlx_loop(data->mlx_ptr);
		}
		else
			ft_error(NULL, argv[1]);
	}
	else
		ft_error("./fdf [FILE]\n", NULL);
	return (0);
}

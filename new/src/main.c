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
		{
			ft_simple_printf("bad file\n");
			return (0);
		}
	}
	return (1);
}

int		ft_esc(int key)
{
	if (key == 53)
	{
		ft_simple_printf("esc\n");
		//mlx_destroy_image(data->img_ptr);
		exit(0);
	}
	else
		ft_simple_printf("key is : %d \n", key);
	return (0);
}

int my_press_key(int key)
{
	ft_simple_printf("result press = %d \n", key);
	return (0);
}

int my_remove_key(int key)
{
	ft_simple_printf("result remove = %d \n", key);
	return (0);
}

int windows_exit()
{
	ft_simple_printf("Bybye\n");
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data *data;

	if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
		return (0);
	if (argc == 2)
	{
		if ((is_good_file(argv[1]) &&
		((data->fd_1 = open(argv[1], O_CLOEXEC)) > 0) &&
		(data->fd_2 = open(argv[1], O_CLOEXEC)) > 0) && ft_read(data))
		{
			data->file = argv[1];
			data->mlx_ptr = mlx_init();
			data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, argv[1]);
			//ft_new_image(data);
			mlx_hook(data->win_ptr, 2, (1L << 01), my_press_key, 0);
			mlx_hook(data->win_ptr, 3, (1L << 01), my_remove_key, 0);
			mlx_key_hook(data->win_ptr, ft_esc, 0);
			mlx_hook(data->win_ptr, 17, 1L << 17, windows_exit, 0);
			mlx_loop(data->mlx_ptr);
		}
		else
			ft_simple_printf("bad file : '%s'\n", argv[1]);
	}
	else
		ft_putstr("no file\n");
	return (0);
}
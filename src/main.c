/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:47:47 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/07 15:47:48 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		is_good_file(char *str)
{
	int end;

	end = 0;
	if (ft_srtlen(str) < 5)
		return (0);
	while (str[end])
		end++;
		//checker fin == .fdf
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

int		main(int argc, char **argv)
{
	t_data	*data;

	if (!(data = (t_data)ft_memalloc(sizeof(t_data))))
		return (0);
	if (argc == 2)
	{
		//if (is_good_file(argv[1]))
		//else ft_putstr("bad file\n");
		//if (!fd = open(path/av[1], O_RDONLY))
		//	ft_putstr("bad file\n"); return (0);
		//ft_parser(fd, data);
		ft_putstr(argv[1]);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(mlx_ptr, 500, 500, argv[1]);
		//ft_tracer here?
		mlx_key_hook(win_ptr, ft_esc, (void*)0);
		mlx_loop(mlx_ptr);
	}
	ft_putstr("no file\n");
	return (0);
}

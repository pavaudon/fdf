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
	if (!(ft_strcmp(str, "42.fdf")))
		return (0);
	//etc ou trouver mieux pour comparer les nom de tet_maps
	return (1);
}

int		ft_esc(int key)
{
	if (key == 53)
	{
		ft_simple_printf("esc\n");
		exit(0);
	}
	else
		ft_simple_printf("key is : %d \n", key);
	return (0);
}

void		ft_init_list(t_data *data)
{
	data->prev = NULL;
	data->next = NULL;
	data->z = 0;
	data->x = 0;
	data->y = 0;
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*data;

	if (!(data = (*t_data)ft_memalloc(t_data)))
		return (0);
	ft_init_list(data);
	if (argc == 2)
	{
		//if (is_good_file(argv[1]))
		//else ft_putstr("bad file\n");
		//if (fd = open(path/av[1], O_RDONLY))
		//ft_parser(fd, data);
		ft_putstr(argv[1]);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, argv[1]);
		//ft_tracer here?
		mlx_key_hook(win_ptr, ft_esc, (void*)0);
		mlx_loop(mlx_ptr);
	}
	ft_putstr("no file\n");
	return (0);
}

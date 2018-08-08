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

/*
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
*/
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

int my_press_key(int key, t_data *data)
{
	ft_simple_printf("result press = %d \n", key);
	return (0);
}

int my_remove_key(int key, t_data *data)
{
	ft_simple_printf("result remove = %d \n", key);
	return (0);
}

int my_mouse_key(int key, t_data *data)
{
	ft_simple_printf("result mouse = %d \n", key);
	return (0);
}

int windows_exit(int key, int i)
{
	ft_simple_printf("Tchuss connard");
	exit(0);
	return (0);
}




// BONUS DE BATARD: FAIRE UNE IMAGE 3 AVEC UNE LICORNE EN PIXEL






int		main(int argc, char **argv)
{
	t_data	*data;
	int y;
	int x;

	if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
		return (0);
	if (argc == 2)
	{
		//if (is_good_file(argv[1]))
		//else ft_putstr("bad file\n");
		//if (!fd = open(path/av[1], O_RDONLY))
		//	ft_putstr("bad file\n"); return (0);
		//ft_parser(fd, data);
		ft_putstr(argv[1]);
		data->mlx_ptr = mlx_init(); // init la mlx
		data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE_X, SIZE_Y, argv[1]); // creer une fenetre de taille  SIZE_X SIZE_Y

		data->img_ptr = mlx_new_image(data->mlx_ptr, SIZE_X, SIZE_Y); // creer une image de taille  SIZE_X SIZE_Y
		data->data_img = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->sl, &data->ed); // recupere le pointeur de l'image (char*)
		data->bpp /= 8; // converti bite en unité

		y = (SIZE_Y / 2) - 50;
		while (y++ < (SIZE_Y / 2) + 50)
		{
			x = (SIZE_X / 2) - 50;
			while (x++ < (SIZE_X / 2) + 50)
			{
				if ((x % 2) == 0 ||  (y % 2) == 0)
					*(unsigned int*)(data->data_img + (x * (data->bpp)) + (y * data->sl)) = 0xFE4D01; // print un int (HEXADECIMAL) dans une position x y donnée 
			}
		}
		*(unsigned int*)(data->data_img + ((SIZE_X / 2) * (data->bpp)) + ((SIZE_Y / 2) * data->sl)) = 0xFE4D01;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0); // affiche l'image sur la windows

		//ft_tracer here?
		// mlx_key_hook(data->win_ptr, ft_esc, (void*)0);
		mlx_hook(data->win_ptr, 2, (1L << 01), my_press_key, &data);// event press sur le clavier
		mlx_hook(data->win_ptr, 3, (1L << 01), my_remove_key, &data); // event relachement du clavier
		mlx_hook(data->win_ptr, 17, 1L << 17, windows_exit, 0); // la croix rouge en haut a gauche
		mlx_mouse_hook (data->win_ptr, my_mouse_key, &data);
		// mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
		mlx_loop(data->mlx_ptr);
	}
	ft_putstr("no file\n");
	return (0);
}

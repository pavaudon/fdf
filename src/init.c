/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:23:38 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/13 12:28:24 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_data(t_data *data)
{
	data->zoom = 20;
	data->tab = NULL;
	data->file = NULL;
	data->depth = 0;
	data->xmove = 0;
	data->ymove = 0;
	if (!(data->bres = (t_bres*)ft_memalloc(sizeof(t_bres))))
		return (0);
	return (1);
}

int		ft_init_mlx(t_data *data, char *argv)
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

void	ft_freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

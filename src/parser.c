/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:10:53 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/09 12:11:05 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_y_max(t_data *data)
{
	int		y;
	char	*line;

	y = 0;
	while (get_next_line(data->fd_1, &line))
		y++;
	data->y_max = y;
	free(line);
	data->fd_1 = close(data->fd_1) == -1;
}

int		ft_read(t_data *data)
{
	int		y;
	char	*line;

	y = 0;
	ft_y_max(data);
	if (!(data->tab = (int**)ft_memalloc(sizeof(int*) * y)))
		return (0);
	if (data->fd_2 > 0)
	{
		y = -1;
		while (get_next_line(data->fd_2, &line))
		{
			if (y < (data->y_max) && !(ft_parser_line(line, data, ++y)))
				return (0);
		}
		free(line);
	}
	else
		return (0);
	return (1);
}

int		ft_strtablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_is_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || (str[i] == '-' && i == 0))
		{
			i++;
			while (str[i] && (ft_isdigit(str[i])))
				i++;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_parser_line(char *line, t_data *data, int y)
{
	int x;
	char **tmp;

	x = -1;
	if (!(tmp = ft_strsplit(line, ' ')))
		return (0);
	data->x_max = (!y) ? ft_strtablen(tmp) : data->x_max;
	if (!(data->tab[y] = (int*)ft_memalloc(sizeof(int) * data->x_max)))
		return (0);
	while (++x < data->x_max)
	{
		//ft_simple_printf("X VALUE : '%d'\n", x);
		if (!(ft_is_nb(tmp[x]) || !ft_atoi(tmp[x])))
			return (0);
		data->tab[y][x] = ft_atoi(tmp[x]);
		//ft_simple_printf("tab[%d][%d] = '%d'\n", y, x, data->tab[y][x]);
	}
	return (1);
}

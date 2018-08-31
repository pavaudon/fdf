/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:43:40 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/31 16:43:41 by pavaudon         ###   ########.fr       */
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
	data->fd_1 = close(data->fd_1);
}

int		ft_read_file(t_data *data)
{
	int		y;
	char	*line;

	y = -1;
	ft_y_max(data);
	if (!(data->tab = (int**)ft_memalloc(sizeof(int*) * data->y_max)))
		return (0);
	if (!(data->x_max = (int*)ft_memalloc(sizeof(int) * data->y_max)))
		return (0);
	if (data->fd_2 > 0)
	{
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
	while (tab[i] != NULL)
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

int		ft_parser_line(char *line, t_data *data, int y)
{
	int x;
	char **tmp;

	x = -1;
	if (!(tmp = ft_strsplit(line, ' ')))
		return (0);
	data->x_max[y] = ft_strtablen(tmp);
	if (!(data->tab[y] = (int*)ft_memalloc(sizeof(int) * data->x_max[y])))
		return (0);
	while (++x < data->x_max[y])
	{
		if (!(ft_is_nb(tmp[x]) || !ft_atoi(tmp[x])))
		{
			free(data->x_max);
			free(data->tab);
			return (0);
		}
		data->tab[y][x] = ft_atoi(tmp[x]);
	}
	ft_freetab(tmp);
	return (1);
}

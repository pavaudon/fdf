/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:30:56 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/07 18:30:57 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_point(t_point *point)
{
	point->prev = NULL;
	point->next = NULL;
	point->z = 0;
	point->x = 0;
	point->y = 0;
}

int		ft_addbackdata(t_point *point, int z, int x, int y)
{
	t_point	*tmp;
	t_point	*new;

	if (!(new = (t_point*)ft_memalloc(sizeof(t_point))))
		return (0);
	new->z = z;
	new->x = x;
	new->y = y;
	new->next = NULL;
	tmp = point;
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
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

int		ft_parser(int fd, t_data *data)
{
	char	*line;
	char	**tmp;
	int		y;
	t_point	*point;

	y = 0;
	line = NULL;
	if (!(t_point*)ft_memalloc(sizeof(t_point)))
		return (0);
	while (get_next_line(fd, *line))
	{
		tmp = ft_strsplit(line);
		ft_fill_data_line(data, tmp, y);
		free(tmp);
		y++;
	}
	data->y_max = y;
	return (1);
}

void	ft_fill_data_line(t_data *data, char **line, int y)
{
	int x;
	int value;

	x = -1;
	while (line[++x])
	{
		if (value = ft_atoi(tmp[x]))
		{
			if (value != 0)
				ft_addbackdata(data->point, value, x, y));
		}
		else
			return (0);
	}
	if (y == 0)
		data->x_max = x;
}

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

int		ft_addbackdata(t_data *data, int z, int x, int y)
{
	t_data	*tmp;
	t_data	*new;

	if (!(new = (t_data*)ft_memalloc(sizeof(t_data))))
		return (0);
	new->z = z;
	new->x = x;
	new->y = y;
	new->next = NULL;
	tmp = data;
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	return (1);
}

void		ft_parser(int fd, t_data *data)
{
	char	*line;
	char	**tmp;
	int		y;
	int		x;

	y = 0;
	while (get_next_line(fd, *line))
	{
		x = -1;
		tmp = ft_strsplit(line);
		while (tmp[++x])
		{
			if (ft_atoi(tmp[x]) != 0)
				ft_addbackdata(data, ft_atoi(tmp[x], x, y))
		}
		free(tmp);
		y++;
	}
}

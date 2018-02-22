/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:42:52 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/21 19:29:45 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			gnl_free_bis(char **line, char **rest, int check)
{
	if (!check)
	{
		if (line && *line)
			ft_strdel(line);
		ft_strdel(rest);
	}
	return (check == 0 ? -1 : 1);
}

static size_t		rest_instance(char *rest, char **line)
{
	size_t			index;
	char			*tmp;

	index = -1;
	*line = NULL;
	if (rest)
	{
		while (rest[++index])
		{
			if (rest[index] == '\n')
			{
				if (!(*line = ft_strndup(rest, index)))
					return (0);
				tmp = rest;
				if (!(rest = ft_strdup(rest + index + 1)))
					return (0);
				free(tmp);
				return (1);
			}
		}
		*line = rest;
		rest = NULL;
	}
	return (2);
}

static size_t		create_line(char *buffer, char **line, size_t index)
{
	char			*tmp;
	char			*buff_copy;

	if (!(buff_copy = ft_strndup(buffer, index)))
		return (0);
	if (*line)
	{
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buff_copy)))
			return (0);
		free(tmp);
		free(buff_copy);
	}
	else
		*line = buff_copy;
	return (1);
}

static size_t		get_line(char *buffer, char *rest, char **line)
{
	size_t			index;
	int				ret;

	index = 0;
	ret = 2;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\n')
	{
		if (!(rest = ft_strdup(buffer + index + 1)))
			return (0);
		ret = 1;
	}
	if (!(create_line(buffer, line, index)))
		return (0);
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static char		*rest = NULL;
	char			buffer[BUFF_SIZE + 1];
	int				check;

	if ((!line || fd < 0) || !(check = rest_instance(rest, line)))
		return (gnl_free_bis(line, &rest, 0));
	if (check == 1)
		return (1);
	while ((check = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[check] = '\0';
		if (!(check = get_line(buffer, rest, line)) || check == 1)
			return (gnl_free_bis(line, &rest, check));
	}
	if (*line && *line[0] != '\0')
		return (1);
	else if (check == 0)
	{
		ft_strdel(line);
		return (0);
	}
	return (gnl_free_bis(line, &rest, 0));
}

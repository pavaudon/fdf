/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:44:50 by pavaudon          #+#    #+#             */
/*   Updated: 2018/01/11 17:58:27 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_domagic(char *s1, char *s2, int n)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strncat(str, s2, n);
	ft_strdel(&s1);
	return (str);
}

static int		check_rest(t_list *file, char **line)
{
	char	*tmp;
	int		cpt;

	cpt = -1;
	*line = NULL;
	if (!file->content)
		return (0);
	while (((char*)(file->content))[++cpt])
	{
		if (((char*)(file->content))[cpt] == '\n')
		{
			*line = ft_strndup((char*)file->content, cpt);
			if (!(tmp = ft_strsub((char*)file->content, cpt + 1,
			ft_strlen((char*)file->content) - cpt)))
				return (-1);
			ft_memdel(&(file->content));
			file->content = (void*)tmp;
			return (1);
		}
	}
	return (0);
}

static int		get_line(t_list *file, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		ret;
	int		check;

	if ((check = check_rest(file, line)))
		return (check);
	if ((ret = read(file->content_size, buffer, BUFF_SIZE)) <= 0)
		return (ret);
	buffer[ret] = '\0';
	if (!file->content)
		file->content = (char*)ft_strndup(buffer, ret);
	else
		file->content = (char*)ft_domagic(file->content, buffer, ret);
	if (!file->content)
		return (-1);
	if ((check = check_rest(file, line)))
		return (check);
	return (get_line(file, line));
}

static t_list	*check_fd(t_list **begin_list, size_t fd)
{
	t_list		*tmp;

	tmp = *begin_list;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(NULL, 0)))
		return (NULL);
	tmp->content_size = fd;
	if (!(*begin_list))
		*begin_list = tmp;
	else
		ft_lstadd_back(*begin_list, tmp);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*begin_list = NULL;
	t_list			*file;
	int				result;

	if ((fd < 0 || !line) || !(file = check_fd(&begin_list, (size_t)fd)))
		return (-1);
	result = get_line(file, line);
	if (!result && file->content && !((char*)file->content)[0])
		return (0);
	else if (!result && file->content)
	{
		*line = (char*)file->content;
		file->content = NULL;
		result = 1;
	}
	return (result);
}

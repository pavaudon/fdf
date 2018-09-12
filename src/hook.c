/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:21:13 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/31 16:21:14 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int windows_exit()
{
	ft_simple_printf("Bybye\n");
	exit(0);
	return (0);
}

int		ft_key(int key, t_data *data)
{
	if (key == 53)
	{
		ft_simple_printf("esc\n");
		exit(0);
	}
	else if (key == 37 && data->data_img)		//l
		which_draw(data, 1);
	else if (key == 35 && data->data_img)		//p
		which_draw(data, 2);
	else if (key == 69) // + calvier num
	{
		data->zoom++;
		which_draw(data, 1);
	}
	else if (key == 78 && data->zoom > 1) // - clavier num
  {
		data->zoom--;
		which_draw(data, 1);
	}
	else if (key == 24) // ++ a cote de delete
	{
		data->depth = 1;
		which_draw(data, 0);
	}
	else if (key == 27)	// -- a cote de delete
	{
		data->depth = -1;
		which_draw(data, 0);
	}

	else if (key == 124)	// >
	{
		data->xmove += (data->xmove < LINE_SIZE) ? 10 : 0;
		which_draw(data, 1);
	}
	else if (key == 123)
	{
		data->xmove -= (data->xmove > 1) ? 10 : 0;
		which_draw(data, 1);
	}
	else if (key == 125) // ++
	{
		data->ymove += (data->ymove < COL_SIZE) ? 10 : 0;
		which_draw(data, 1);
	}
	else if (key == 126)	// --
	{
		data->ymove -= (data->ymove > 1) ? 10 : 0;
		which_draw(data, 1);
	}

	else
		ft_simple_printf("key is : %d \n", key);
	return (0);
}

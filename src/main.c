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

void ft_error(char *error)
{
	ft_putendl(error);
	exit(1);
}

void check_arg(t_env *e, char *arg)
{
	if (ft_strstr(arg, ".fdf\0"))
	{
		ft_error("La phrase ne dois pas etre egale a 'Prout' ... Sorry");
	}
}

int main(int argc, char **argv)
{
	t_env e;

	if (argc == 2)
	{
		check_arg(&e, argv[1]);
	}
	ft_error("usage: fdf [file name path]");	
	return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:48:03 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/20 15:45:50 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int			main(int ac, char **av)
{
	if (ac < 2)
		error("Usage : ./fdf <filename>");
	else
		parse_map(&av[1]);
	//mlx_loop(e.mlx);
	return (0);
}

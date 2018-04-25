/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:48:03 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/25 17:38:19 by aabelque         ###   ########.fr       */
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
	t_env	*e;
	int		i;

	i = 0;
	if (ac < 2)
		error("Usage : ./fdf <filename>");
	if (!(e = ft_memalloc(sizeof(t_env))))
		ft_error_malloc();
	parse_map(&av[1], e);
	init_mlx(e);
	mlx_loop(e->mlx);
	return (0);
}

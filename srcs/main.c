/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:48:03 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/03 17:17:12 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *str)
{
	ft_putendl(str);
	exit(1);
}

char		*display_controls(void)
{
	char	*str;

	str = "\
CONTROLS: \n\
\n\
Quit-> \n\
	ESC \n\
\n\
Color-> \n\
	C\n\
";
	return (str);
}

void		display_controls2(void)
{
	ft_putstr("\
__________________________\n\
CONTROLS:\n\
\n\
Quit:\n\
	KEY: ESC\n\
\n\
Color:\n\
	KEY: C\n\
__________________________\n\
");
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
	display_controls2();
	parse_map(&av[1], e);
	init_mlx(e);
	mlx_loop(e->mlx);
	return (0);
}

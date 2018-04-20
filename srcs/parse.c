/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:32:09 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/20 15:45:30 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_nb_line(char **av)
{
	int		line;
	char	buf;
	t_env	e;

	line = 0;
	if ((e.fd = open(*av, O_RDONLY)) < 0)
		ft_error_map();
	while (read(e.fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			line++;
	}
	close(e.fd);
	return (line);
}

void		parse_map(char **av)
{
	char	*line;
	t_env	*e;
	int		i;

	if (!(e = ft_memalloc(sizeof(t_env))))
		ft_error_malloc();
	e->map.nb_line = ft_nb_line(av);
	if ((e->fd = open(*av, O_RDONLY)) > 0)
	{
		while ((e->ret = get_next_line(e->fd, &line)) > 0)
		{
			i = 0;
			e->map.line = ft_strsplit(line, ' ');
			free(line);
			while (e->map.line[i])
			{
				ft_putstr(e->map.line[i]);
				i++;
			}
			write(1, "\n", 1);
			free_tab(e->map.line);
		}
	}
}

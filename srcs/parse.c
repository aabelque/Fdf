/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:32:09 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/25 17:50:58 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_vec(t_env *e, int j)
{
	int		i;
	t_vec	vec;
	t_list	*tmp;

	i = 0;
	while (e->map.line[i])
	{
		vec.x = (float)i * SCALE + 500;
		vec.y = (float)j * SCALE + 500;
		vec.z = (float)ft_atoi(e->map.line[i]);
		if (!(tmp = ft_lstnew((void const *)&vec, sizeof(t_vec))))
			ft_error_malloc();
		ft_pushback_list(&e->map.vector, tmp);
		i++;
	}
}

void		parse_map(char **av, t_env *e)
{
	char	*line;
	int		j;

	j = 0;
	if ((e->fd = open(*av, O_RDONLY)) > 0)
	{
		while ((e->ret = get_next_line(e->fd, &line)) > 0)
		{
			e->map.line = ft_strsplit(line, ' ');
			e->map.pt_line = ft_valid_map(e);
			create_vec(e, j);
			free(line);
			free_tab(e->map.line);
			j++;
		}
		e->map.nb_line = j;
		e->map.points = e->map.pt_line * e->map.nb_line;
	}
}

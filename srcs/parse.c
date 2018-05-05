/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:32:09 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/05 14:22:13 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			*lst_to_array(t_list *vector)
{
	size_t		size_v;
	size_t		nb_v;
	size_t		i;
	char		*mat;

	size_v = vector->content_size;
	nb_v = ft_nb_elemlist(vector);
	i = 0;
	if (!(mat = ft_memalloc(nb_v * size_v)))
		ft_error_malloc();
	while (i < nb_v)
	{
		ft_memcpy(&(mat[i * size_v]), vector->content, size_v);
		vector = vector->next;
		i++;
	}
	return (mat);
}

void			create_vec(t_env *e, int j)
{
	int			i;
	t_vec		vec;
	t_list		*tmp;

	i = 0;
	while (e->map.line[i])
	{
		vec.x = (float)i * SCALE + 200;
		vec.y = (float)j * SCALE + 200;
		vec.z = (float)ft_atoi(e->map.line[i]);
		if (!(tmp = ft_lstnew((void const *)&vec, sizeof(t_vec))))
			ft_error_malloc();
		ft_pushback_list(&e->map.vector, tmp);
		i++;
	}
}

void			parse_map(char **av, t_env *e)
{
	char		*line;
	int			j;

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
		e->map.vertex = lst_to_array(e->map.vector);
	}
}

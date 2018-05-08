/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:11:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/08 18:20:25 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_center(t_env *e)
{
	t_vec	c;

	c = e->center;
	c.x = (e->map.vertex[(e->map.nb_line) * e->map.pt_line - 1].x +
			e->map.vertex[0].x) / 2;
	c.y = (e->map.vertex[(e->map.nb_line) * e->map.pt_line - 1].y +
			e->map.vertex[0].y) / 2;
	e->center = c;
}

int			out_map(t_vec *vertex)
{
	if (vertex->x >= X_WIN || vertex->x < 0 ||
				vertex->y >= Y_WIN || vertex->y < 0)
		return (1);
	else
		return (0);
}

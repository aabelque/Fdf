/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:11:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/05 17:12:46 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_center(t_env *e)
{
	t_vec	c;
	int		xc;
	int		yc;

	c = e->center;
	xc = e->map.pt_line;
	yc = e->map.nb_line;
	c.x = xc / 2 + yc / 2;
	c.y = yc / 2 + xc / 2;
	e->center = c;
}

void		map_control(t_env *e)
{
	int		wx;
	int		wy;
	float	s;

	wx = X_WIN / 2;
	wy = Y_WIN / 2;
	e->center.x == 0 ? e->center.x = 100 : e->center.x;
	s = (wx - 1200) / (e->center.x);
	matcal_transl(e, -e->center.x + wx, -e->center.y + wy, 0);
	matcal_scal(e, s);
}

int			out_map(t_vec *vertex)
{
	if (!(vertex->x > X_WIN + 100 || vertex->x <= 0 ||
				vertex->y > Y_WIN + 100 || vertex->y <= 0))
		return (1);
	else
		return (0);
}

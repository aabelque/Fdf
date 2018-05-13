/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:05:55 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/13 18:40:50 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calculated_cav(t_vec *m, t_matransf *mt, t_env *e)
{
	double		tx;
	double		ty;
	double		tz;
	double		tw;

	m->x -= e->center.x;
	m->y -= e->center.y;
	tx = mt->v1.x * m->x + mt->v2.x * m->y + mt->v3.x * m->z + mt->v4.x;
	ty = mt->v1.y * m->x + mt->v2.y * m->y + mt->v3.y * m->z + mt->v4.y;
	tz = mt->v1.z * m->x + mt->v2.z * m->y + mt->v3.z * m->z + mt->v4.z;
	tw = mt->v1.w * m->x + mt->v2.w * m->y + mt->v3.w * m->z + mt->v4.w;
	m->x = tx;
	m->y = ty;
	m->z = tz;
	m->w = tw;
	m->x += e->center.x;
	m->y += e->center.y;
}

double			rad_deg(double deg)
{
	return (deg * M_PI / 180);
}

t_matransf		matrixcav(double deg)
{
	t_matransf	matpers;

	matpers.v1 = newvec(1.0, 0.0, 0.0, 0.0);
	matpers.v2 = newvec(0.0, 1.0, 0.0, 0.0);
	matpers.v3 = newvec((1 / 2) * cos(deg), (1 / 2) * sin(deg), 0.0, 0.0);
	matpers.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matpers);
}

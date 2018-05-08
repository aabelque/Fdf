/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:22:16 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/07 15:56:51 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calculated_matrice(t_vec *m, t_matransf *mt, t_env *e)
{
	double	tx;
	double	ty;
	double	tz;
	double	tw;

	m->x -= e->center.x;
	m->y -= e->center.y;
	tx = mt->v1.x * m->x + mt->v2.x * m->y + mt->v3.x * m->z + mt->v4.x * m->w;
	ty = mt->v1.y * m->x + mt->v2.y * m->y + mt->v3.y * m->z + mt->v4.y * m->w;
	tz = mt->v1.z * m->x + mt->v2.z * m->y + mt->v3.z * m->z + mt->v4.z * m->w;
	tw = mt->v1.w * m->x + mt->v2.w * m->y + mt->v3.w * m->z + mt->v4.w * m->w;
	m->x = tx;
	m->y = ty;
	m->z = tz;
	m->w = tw;
	m->x += e->center.x;
	m->y += e->center.y;
}

void		matcal_rot(t_env *e, double deg, char axe)
{
	t_matransf calrmat;

	if (axe == 'x')
		calrmat = rotxmat(deg);
	else if (axe == 'y')
		calrmat = rotymat(deg);
	else
		calrmat = rotzmat(deg);
	apply_calmat(e, e->map.vertex, &calrmat);
}

void		matcal_transl(t_env *e, double x, double y, double z)
{
	t_matransf caltmat;

	caltmat = transl_mat(x, y, z);
	apply_calmat(e, e->map.vertex, &caltmat);
}

void		matcal_scal(t_env *e, double s)
{
	t_matransf	calsmat;

	calsmat = scal_mat(s);
	apply_calmat3(e, e->map.vertex, &calsmat);
}

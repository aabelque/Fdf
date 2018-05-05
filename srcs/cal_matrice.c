/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:22:16 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/05 18:09:44 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		radian_deg(float deg)
{
	return (deg * M_PI / 180.0);
}

void		calculated_matrice(t_vec *m, t_matransf *mt)
{
	float	tx;
	float	ty;
	float	tz;
	float	tw;

	tx = mt->v1.x * m->x + mt->v2.x * m->y + mt->v3.x * m->z + mt->v4.x * m->w;
	ty = mt->v1.y * m->x + mt->v2.y * m->y + mt->v3.y * m->z + mt->v4.y * m->w;
	tz = mt->v1.z * m->x + mt->v2.z * m->y + mt->v3.z * m->z + mt->v4.z * m->w;
	tw = mt->v1.w * m->x + mt->v2.w * m->y + mt->v3.w * m->z + mt->v4.w * m->w;
	m->x = tx;
	m->y = ty;
	m->z = tz;
	m->w = tw;
}

void		matcal_rot(t_env *e, float deg, char axe)
{
	t_matransf calrmat;
//	float radeg;

//	radeg = radian_deg(deg);
	if (axe == 'x')
		calrmat = rotxmat(deg);
	else if (axe == 'y')
		calrmat = rotymat(deg);
	else
		calrmat = rotzmat(deg);
	apply_calmat(e, e->map.vertex, &calrmat);
	apply_calmat2(e, e->map.vertex, &calrmat);
}

void		matcal_transl(t_env *e, float x, float y, float z)
{
	t_matransf caltmat;

	caltmat = transl_mat(x, y, z);
	apply_calmat(e, e->map.vertex, &caltmat);
	apply_calmat2(e, e->map.vertex, &caltmat);
}

void		matcal_scal(t_env *e, float s)
{
	t_matransf	calsmat;

	calsmat = scal_mat(s);
	apply_calmat(e, e->map.vertex, &calsmat);
	apply_calmat2(e, e->map.vertex, &calsmat);
}

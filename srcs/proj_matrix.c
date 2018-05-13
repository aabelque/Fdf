/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:05:55 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/13 12:32:50 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calculated_z(t_vec *m, t_matransf *mt, t_env *e)
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
	m->x -= e->dega;
	m->y -= e->dega;
	m->z -= e->dega;
	m->w -= e->dega;
	m->x += e->center.x;
	m->y += e->center.y;
}

void			calculated_pers(t_vec *m, t_matransf *mt, t_env *e)
{
	double		tx;
	double		ty;
	double		tz;
	double		tw;

	(void)e;
	m->w = m->z;
//	m->x -= e->center.x;
//	m->y -= e->center.y;
	tx = mt->v1.x * m->x + mt->v2.x * m->y + mt->v3.x * m->z + mt->v4.x;
	ty = mt->v1.y * m->x + mt->v2.y * m->y + mt->v3.y * m->z + mt->v4.y;
	tz = mt->v1.z * m->x + mt->v2.z * m->y + mt->v3.z * m->z + mt->v4.z;
	tw = mt->v1.w * m->x + mt->v2.w * m->y + mt->v3.w * m->z + mt->v4.w;
	m->x = tx;
	m->y = ty;
	m->z = tz;
	//m->w = tw;
	if (tw != 1)
	{
		m->x /= tw;
		m->y /= tw;
		m->z /= tw;
	}
//	m->x += e->center.x;
//	m->y += e->center.y;
}

double			rad_deg(double deg)
{
	return (deg * M_PI / 180);
}

t_matransf		matrixpers(double fov, double nz, double fz)
{
	t_matransf	matpers;
	double		zrange;
	double		tanfov;
//	double		tanfov2;

	zrange = fz - nz;
	tanfov = tan(rad_deg(fov / 2));
//	tanfov2 = tan(rad_deg(fov2 / 2));
	matpers.v1 = newvec((1 / tanfov), 0.0, 0.0, 0.0);
	matpers.v2 = newvec(0.0, (1 / tanfov), 0.0, 0.0);
	matpers.v3 = newvec(0.0, 0.0, -fz / zrange, -(fz * nz) / zrange);
	matpers.v4 = newvec(0.0, 0.0, -1.0, 0.0);
	return (matpers);
}

t_matransf		matrix_z(double z)
{
	t_matransf	mat_z;
	
	(void)z;
	mat_z.v1 = newvec(1.0, 0.0, 0.0, 0.0);
	mat_z.v2 = newvec(0.0, 1.0, 0.0, 0.0);
	mat_z.v3 = newvec(0.0, 0.0, z, 0.0);
	mat_z.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (mat_z);
}

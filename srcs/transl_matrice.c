/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transl_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:46:10 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/12 11:23:17 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calculated_scal(t_vec *m, t_matransf *mt, t_env *e)
{
	double		tx;
	double		ty;
	double		tz;
	double		tw;

	m->x -= e->center.x;
	m->y -= e->center.y;
	tx = mt->v1.x * m->x;
	ty = mt->v2.y * m->y;
	tz = mt->v3.z * m->z;
	tw = mt->v4.w * m->w;
	m->x = tx;
	m->y = ty;
	m->z = tz;
	m->w = tw;
	m->x += e->center.x;
	m->y += e->center.y;
}

t_matransf		transl_mat(double x, double y, double z)
{
	t_matransf	matransl;

	matransl.v1 = newvec(1.0, 0.0, 0.0, 0.0);
	matransl.v2 = newvec(0.0, 1.0, 0.0, 0.0);
	matransl.v3 = newvec(0.0, 0.0, 1.0, 0.0);
	matransl.v4 = newvec(x, y, z, 1.0);
	return (matransl);
}

t_matransf		scal_mat(double s)
{
	t_matransf	matscal;

	matscal.v1 = newvec(s, 0.0, 0.0, 0.0);
	matscal.v2 = newvec(0.0, s, 0.0, 0.0);
	matscal.v3 = newvec(0.0, 0.0, s, 0.0);
	matscal.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matscal);
}

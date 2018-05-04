/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:22:16 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/04 18:17:59 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec		calculated_matrice(t_vec *m, t_matransf *mt)
{
	t_vec	n;

	n.x = mt->v1.x * m->x + mt->v2.x * m->y + mt->v3.x * m->z + mt->v4.x * m->w;
	n.y = mt->v1.y * m->x + mt->v2.y * m->y + mt->v3.y * m->z + mt->v4.y * m->w;
	n.z = mt->v1.z * m->x + mt->v2.z * m->y + mt->v3.z * m->z + mt->v4.z * m->w;
	n.w = mt->v1.w * m->x + mt->v2.w * m->y + mt->v3.w * m->z + mt->v4.w * m->w;
	return (n);
}

void		apply_calmat(t_env *e, t_vec *m, t_matransf *mt)
{
}

void		matcal_rot(t_env *e, float deg, char axe)
{
}

void		matcal_transl(t_env *e, float x, float y, float z)
{
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:05:32 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/05 18:07:32 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec			newvec(float x, float y, float z, float w)
{
	return ((t_vec){x, y, z, w});
}

t_matransf		rotxmat(float deg)
{
	t_matransf	matrotx;

	matrotx.v1 = newvec(1.0, 0.0, 0.0, 0.0);
	matrotx.v2 = newvec(0.0, cosf(deg), sinf(deg), 0.0);
	matrotx.v3 = newvec(0.0, -sinf(deg), cosf(deg), 0.0);
	matrotx.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matrotx);
}

t_matransf		rotymat(float deg)
{
	t_matransf	matroty;

	matroty.v1 = newvec(cosf(deg), 0.0, -sinf(deg), 0.0);
	matroty.v2 = newvec(0.0, 1.0, 0.0, 0.0);
	matroty.v3 = newvec(sinf(deg), 0.0, cosf(deg), 0.0);
	matroty.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matroty);
}

t_matransf		rotzmat(float deg)
{
	t_matransf	matrotz;

	matrotz.v1 = newvec(cosf(deg), sinf(deg), 0.0, 0.0);
	matrotz.v2 = newvec(-sinf(deg), cosf(deg), 0.0, 0.0);
	matrotz.v3 = newvec(0.0, 0.0, 1.0, 0.0);
	matrotz.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matrotz);
}

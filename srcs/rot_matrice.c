/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:05:32 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/12 17:15:06 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec			newvec(double x, double y, double z, double w)
{
	return ((t_vec){x, y, z, w});
}

t_matransf		rotxmat(double deg)
{
	t_matransf	matrotx;

	matrotx.v1 = newvec(1.0, 0.0, 0.0, 0.0);
	matrotx.v2 = newvec(0.0, cos(deg), sin(deg), 0.0);
	matrotx.v3 = newvec(0.0, -sin(deg), cos(deg), 0.0);
	matrotx.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matrotx);
}

t_matransf		rotymat(double deg)
{
	t_matransf	matroty;

	matroty.v1 = newvec(cos(deg), 0.0, -sin(deg), 0.0);
	matroty.v2 = newvec(0.0, 1.0, 0.0, 0.0);
	matroty.v3 = newvec(sin(deg), 0.0, cos(deg), 0.0);
	matroty.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matroty);
}

t_matransf		rotzmat(double deg)
{
	t_matransf	matrotz;

	matrotz.v1 = newvec(cos(deg), sin(deg), 0.0, 0.0);
	matrotz.v2 = newvec(-sin(deg), cos(deg), 0.0, 0.0);
	matrotz.v3 = newvec(0.0, 0.0, 1.0, 0.0);
	matrotz.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matrotz);
}

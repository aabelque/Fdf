/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transl_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:46:10 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/04 17:37:34 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matransf		transl_mat(float x, float y, float z)
{
	t_matransf	matransl;

	matransl.v1 = newvec(1.0, 0.0, 0.0, 0.0);
	matransl.v2 = newvec(0.0, 1.0, 0.0, 0.0);
	matransl.v3 = newvec(0.0, 0.0, 1.0, 0.0);
	matransl.v4 = newvec(x, y, z, 1.0);
	return (matransl);
}

t_matransf		scal_mat(float s)
{
	t_matransf	matscal;

	matscal.v1 = newvec(s, 0.0, 0.0, 0.0);
	matscal.v2 = newvec(0.0, s, 0.0, 0.0);
	matscal.v3 = newvec(0.0, 0.0, s, 0.0);
	matscal.v4 = newvec(0.0, 0.0, 0.0, 1.0);
	return (matransl);
}

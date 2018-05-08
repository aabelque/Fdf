/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_calmat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:17:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/08 16:12:48 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		apply_calmat(t_env *e, t_vec *m, t_matransf *mt)
{
	int		i;

	i = 0;
	while (i < e->map.points)
	{
		calculated_matrice(m, mt, e);
		i++;
		m++;
	}
}

void		apply_calmat3(t_env *e, t_vec *m, t_matransf *mt)
{
	int		i;

	i = 0;
	while (i < e->map.points)
	{
		calculated_scal(m, mt, e);
		i++;
		m++;
	}
}

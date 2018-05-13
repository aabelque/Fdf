/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_calmat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:17:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/11 17:57:51 by aabelque         ###   ########.fr       */
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

void		apply_calmat2(t_env *e, t_vec *m, t_matransf *mt)
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

void		apply_calmat3(t_env *e, t_vec *m, t_matransf *mt)
{
	int		i;

	i = 0;
	while (i < e->map.points)
	{
		calculated_pers(m, mt, e);
		i++;
		m++;
	}
}

void		apply_calmat4(t_env *e, t_vec *m, t_matransf *mt)
{
	int		i;

	i = 0;
	while (i < e->map.points)
	{
		calculated_z(m, mt, e);
		i++;
		m++;
	}
}

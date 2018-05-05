/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_calmat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:17:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/05 18:07:29 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			apply_calmat2(t_env *e, t_vec *m, t_matransf *mt)
{
	//t_vec		*tmp;
	int			x;
	int			y;

//	tmp = e->map.vertex;
	y = 0;
	while (y < e->map.nb_line + 1)
	{
		x = 0;
		while (x < e->map.pt_line)
		{
			e->mat.a = *m;
			e->mat.b = *(m + 1);
			calculated_matrice(m, mt);
			x++;
			m++;
		}
		m++;
		y++;
	}
}

void			apply_calmat(t_env *e, t_vec *m, t_matransf *mt)
{
//	t_vec		*tmp;
	int			x;
	int			y;

//	tmp = e->map.vertex;
	y = 0;
	while (y < e->map.nb_line)
	{
		x = 0;
		while (x < e->map.pt_line + 1)
		{
			e->mat.a = *m;
			e->mat.b = *(m + 1);
			calculated_matrice(m, mt);
			x++;
			m++;
		}
		m++;
		y++;
	}
}

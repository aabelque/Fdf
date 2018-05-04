/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:08:02 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/04 18:15:59 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env *e)
{
	t_vec	*tmp;
	int		x;
	int		y;

	tmp = e->map.matrice;
	y = 0;
	while (y < e->map.nb_line)
	{
		x = 0;
		while (x < e->map.pt_line - 1)
		{
			e->mat.a = *tmp;
			e->mat.b = *(tmp + 1);
			bresenham(e, e->img.addr);
			x++;
			tmp++;
		}
		tmp++;
		y++;
	}
}

void		draw2(t_env *e)
{
	t_vec	*tmp;
	int		x;
	int		y;

	tmp = e->map.matrice;
	y = 0;
	while (y < e->map.nb_line - 1)
	{
		x = 0;
		while (x < e->map.pt_line)
		{
			e->mat.a = *(tmp + y * e->map.pt_line + x);
			e->mat.b = *(tmp + (y + 1) * e->map.pt_line + x);
			bresenham(e, e->img.addr);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:08:02 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/02 17:36:44 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env *e)
{
	t_vec	a;
	t_vec	b;
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
			a = *tmp;
			b = *(tmp + 1);
			bresenham(a, b, e->img.addr);
			x++;
			tmp++;
		}
		tmp++;
		y++;
	}
}

void		draw2(t_env *e)
{
	t_vec	a;
	t_vec	b;
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
			a = *(tmp + y * e->map.pt_line + x);
			b = *(tmp + (y + 1) * e->map.pt_line + x);
			bresenham(a, b, e->img.addr);
			x++;
		}
		y++;
	}
}

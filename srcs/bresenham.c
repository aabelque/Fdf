/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:12:27 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/13 12:05:11 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		bresenham2(t_env *e, t_vec2 er, int *addr)
{
	t_vec2			d;
	t_vec2			in;
	int				ddy;
	int				i;

	i = 0;
	d = (t_vec2){2 * er.x, 2 * er.y};
	ddy = er.y;
	in.x = e->mat.a.x > e->mat.b.x ? -1 : 1;
	in.y = e->mat.a.y > e->mat.b.y ? -1 : 1;
	while (i <= ddy)
	{
		if (!out_map(&e->mat.a))
			addr[(int)e->mat.a.x + (int)e->mat.a.y * X_WIN] = e->color;
		i++;
		e->mat.a.y += in.y;
		er.y -= d.x;
		if (er.y < 0)
		{
			e->mat.a.x += in.x;
			er.y += d.y;
		}
	}
}

static	void		bresenham1(t_env *e, t_vec2 er, int *addr)
{
	t_vec2			d;
	t_vec2			in;
	int				ddx;
	int				i;

	i = 0;
	d = (t_vec2){2 * er.x, 2 * er.y};
	ddx = er.x;
	in.x = e->mat.a.x > e->mat.b.x ? -1 : 1;
	in.y = e->mat.a.y > e->mat.b.y ? -1 : 1;
	while (i <= ddx)
	{
		if (!out_map(&e->mat.a))
			addr[(int)e->mat.a.x + (int)e->mat.a.y * X_WIN] = e->color2;
		i++;
		e->mat.a.x += in.x;
		er.x -= d.y;
		if (er.x < 0)
		{
			e->mat.a.y += in.y;
			er.x += d.x;
		}
	}
}

void				bresenham(t_env *e, int *addr)
{
	t_vec2			er;
	int				ddx;
	int				ddy;

	er.x = fabs(e->mat.b.x - e->mat.a.x);
	er.y = fabs(e->mat.b.y - e->mat.a.y);
	ddx = er.x;
	ddy = er.y;
	if (ddx >= ddy)
		bresenham1(e, er, addr);
	if (ddx < ddy)
		bresenham2(e, er, addr);
}

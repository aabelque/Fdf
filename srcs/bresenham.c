/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:12:27 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/25 18:37:39 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		bresenham2(t_vec a, t_vec b, t_vec2 er, int *addr)
{
	t_vec2			d;
	t_vec2			in;
	int				ddy;
	int				i;

	i = 0;
	d = (t_vec2){2 * er.x, 2 * er.y};
	//in = (t_vec2){1, 1};
	ddy = er.y;
	in.x = a.x > b.x ? -1 : 1;
	in.y = a.y > b.y ? -1 : 1;
	while (i <= ddy)
	{
		addr[(int)a.x + (int)a.y * X_WIN] = C_WHITE;
		i++;
		a.y += in.y;
		er.y -= d.x;
		if (er.y < 0)
		{
			a.x += in.x;
			er.y += d.y;
		}
	}
}

static	void		bresenham1(t_vec a, t_vec b, t_vec2 er, int *addr)
{
	t_vec2			d;
	t_vec2			in;
	int				ddx;
	int				i;

	i = 0;
	d = (t_vec2){2 * er.x, 2 * er.y};
//	in = (t_vec2){1, 1};
	ddx = er.x;
	in.x = a.x > b.x ? -1 : 1;
	in.y = a.y > b.y ? -1 : 1;
	while (i <= ddx)
	{
		addr[(int)a.x + (int)a.y * X_WIN] = C_WHITE;
		i++;
		a.x += in.x;
		er.x -= d.y;
		if (er.x < 0)
		{
			a.y += in.y;
			er.x += d.x;
		}
	}
}

void				bresenham(t_vec a, t_vec b, int	*addr)
{
	t_vec2			er;
	int				ddx;
	int				ddy;

	er.x = fabs(b.x - a.x);
	er.y = fabs(b.y - a.y);
	ddx = er.x;
	ddy = er.y;

	if (ddx > ddy)
		bresenham1(a, b, er, addr);
	if (ddx < ddy)
		bresenham2(a, b, er, addr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:08:02 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/30 18:02:10 by aabelque         ###   ########.fr       */
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

	x = 2;
	tmp = e->map.matrice;
	while (x <= e->map.points)
	{
		y = 0;
		while (y <= e->map.nb_line)
		{
			a = *tmp;
			b = *(tmp + 1);
			bresenham(a, b, e->img.addr);
			y++;
		}
		tmp++;
		x++;
	}
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image");
}

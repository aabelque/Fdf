/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:07:41 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/23 17:45:44 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, void *param)
{
	if (keycode == K_ESC)
		exit(1);
	(void)param;
	return (0);
}

int		loop_hook(t_env *e)
{
	t_vec	vec;

	while (e->map.vector)
	{
		vec = *((t_vec*)(e->map.vector->content));
		e->img.addr[(int)vec.y * e->img.s_line/4 + (int)vec.x] = C_WHITE;
		e->map.vector = e->map.vector->next;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int		init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X_WIN, Y_WIN, "FDF");
	e->img.img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	e->img.addr = (int*)mlx_get_data_addr(e->img.img, &(e->img.bpp),
			&(e->img.s_line), &(e->img.endian));
	mlx_loop_hook(e->mlx, loop_hook, &(*e));
	mlx_key_hook(e->win, key_hook, &(*e));
	return (0);
}

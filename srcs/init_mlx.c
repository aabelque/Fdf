/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:07:41 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/05 17:15:09 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		redraw(t_env *e)
{
	char	*str;

	str = display_controls();
	e->img.img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	e->img.addr = (int *)mlx_get_data_addr(e->img.img, &(e->img.bpp),
			&(e->img.s_line), &(e->img.endian));
	draw(e);
	draw2(e);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image");
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 1, C_WHITE, str);
}

int			expose_hook(t_env *e)
{
	redraw(e);
	return (0);
}

int			loop_hook(t_env *e)
{
	char	*str;

	str = display_controls();
//	map_control(e);
	draw(e);
	draw2(e);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image");
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 1, C_WHITE, str);
	return (0);
}

int			init_mlx(t_env *e)
{
	set_colors(&(e->color));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X_WIN, Y_WIN, "FDF");
	e->img.img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	e->img.addr = (int*)mlx_get_data_addr(e->img.img, &(e->img.bpp),
			&(e->img.s_line), &(e->img.endian));
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	return (0);
}

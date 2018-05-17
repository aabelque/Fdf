/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:07:41 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/17 11:07:34 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		redraw(t_env *e)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	str = display_controls();
	str2 = display_controls3();
	str3 = display_controls4();
	str4 = display_controls5();
	e->img.img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	e->img.addr = (int *)mlx_get_data_addr(e->img.img, &(e->img.bpp),
			&(e->img.s_line), &(e->img.endian));
	draw(e);
	draw2(e);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image", e);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 1, C_WHITE, str);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 20, C_WHITE, str2);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 39, C_WHITE, str3);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 58, C_WHITE, str4);
}

int			expose_hook(t_env *e)
{
	redraw(e);
	return (0);
}

int			loop_hook(t_env *e)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	str = display_controls();
	str2 = display_controls3();
	str3 = display_controls4();
	str4 = display_controls5();
	draw(e);
	draw2(e);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image", e);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 1, C_WHITE, str);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 20, C_WHITE, str2);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 39, C_WHITE, str3);
	mlx_string_put(e->mlx, e->win, X_WIN - 400, 58, C_WHITE, str4);
	return (0);
}

int			init_mlx(t_env *e)
{
	set_colors(&(e->color));
	set_colors2(&(e->color2));
	if ((e->mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	e->win = mlx_new_window(e->mlx, X_WIN, Y_WIN, "FDF");
	e->img.img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	e->img.addr = (int*)mlx_get_data_addr(e->img.img, &(e->img.bpp),
			&(e->img.s_line), &(e->img.endian));
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	return (0);
}

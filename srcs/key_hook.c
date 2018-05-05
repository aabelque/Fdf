/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:25:41 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/05 16:58:07 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	key_hook_rot(int keycode, t_env *e)
{
	if (keycode == K_ROTX)
		matcal_rot(e, MOVXUP, 'x');
	if (keycode == K_ROTX2)
		matcal_rot(e, MOVXDO, 'x');
	if (keycode == K_ROTY)
		matcal_rot(e, MOVYUP, 'y');
	if (keycode == K_ROTY2)
		matcal_rot(e, MOVYDO, 'y');
	if (keycode == K_ROTZ)
		matcal_rot(e, MOVZUP, 'z');
	if (keycode == K_ROTZ2)
		matcal_rot(e, MOVZDO, 'z');
}

static	void	key_hook_transl(int keycode, t_env *e)
{
	if (keycode == K_UP)
		matcal_transl(e, 0, TUP, 0);
	if (keycode == K_DOWN)
		matcal_transl(e, 0, TDO, 0);
	if (keycode == K_LEFT)
		matcal_transl(e, TLEFT, 0, 0);
	if (keycode == K_RIGHT)
		matcal_transl(e, TRIGHT, 0, 0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	if (keycode == K_COLORS)
		set_colors(&(e->color));
	key_hook_rot(keycode, e);
	key_hook_transl(keycode, e);
	mlx_destroy_image(e->mlx, e->img.img);
	expose_hook(e);
	return (0);
}

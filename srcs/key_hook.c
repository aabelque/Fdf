/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:25:41 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/14 11:21:05 by aabelque         ###   ########.fr       */
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
	{
		e->center.y += TUP;
		matcal_transl(e, 0, TUP, 0);
	}
	if (keycode == K_DOWN)
	{
		e->center.y += TDO;
		matcal_transl(e, 0, TDO, 0);
	}
	if (keycode == K_LEFT)
	{
		e->center.x += TLEFT;
		matcal_transl(e, TLEFT, 0, 0);
	}
	if (keycode == K_RIGHT)
	{
		e->center.x += TRIGHT;
		matcal_transl(e, TRIGHT, 0, 0);
	}
	if (keycode == K_CAV)
		matcal_cav(e, 63.4);
}

static	void	key_hook_scal(int keycode, t_env *e)
{
	if (keycode == K_SPLUS)
		matcal_scal(e, SPLUS);
	if (keycode == K_SLESS)
		matcal_scal(e, SLESS);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_FAILURE);
	}
	if (keycode == K_G)
	{
		e->color = C_WHITE;
		e->color2 = C_WHITE;
	}
	if (keycode == K_V)
		e->color = C_BLACK;
	if (keycode == K_B)
		e->color2 = C_BLACK;
	if (keycode == K_COLORS)
	{
		set_colors(&e->color);
		set_colors2(&e->color2);
	}
	key_hook_rot(keycode, e);
	key_hook_transl(keycode, e);
	key_hook_scal(keycode, e);
	mlx_destroy_image(e->mlx, e->img.img);
	expose_hook(e);
	return (0);
}

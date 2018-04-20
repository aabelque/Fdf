/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:07:41 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/16 13:31:57 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X_WIN, Y_WIN, "FDF");
	e->img->img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	e->img->addr = (int*)mlx_get_data_addr(e->img->img, &(e->img->bpp),
			&(e->img->s_line), &(e->img->endian));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:37:03 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/02 17:56:29 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		set_colors(void)
{
	int	*colors;
	static

	if (!(colors = ft_memalloc(sizeof(int) * NB_COLORMAX)))
		return (NULL);
	colors = { C_WHITE, C_RED, C_GREEN, C_BLUE, C_ABR, C_ACA, C_AMA, C_AYELL,
		C_YELL, C_ARED, C_AUB, C_AZUR, C_AZUR1, C_CBLUE, C_LAV,C_BORD, C_BRUN,
		C_BLUEF, C_GREY, C_GREYA, C_BROWN, C_OLIV, C_ORANGE, C_MILITARY };

}

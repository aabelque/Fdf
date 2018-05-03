/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:37:03 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/03 14:31:08 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	set_tab_color(int *color)
{
	color[0] = C_OLIV;
	color[1] = C_WHITE;
	color[2] = C_RED;
	color[3] = C_GREEN;
	color[4] = C_BLUE;
	color[5] = C_ABR;
	color[6] = C_ACA;
	color[7] = C_AMA;
	color[8] = C_AYELL;
	color[9] = C_YELL;
	color[10] = C_ARED;
	color[11] = C_AIM;
	color[12] = C_AZUR;
	color[13] = C_AZUR1;
	color[14] = C_CBLUE;
	color[15] = C_LAV;
	color[16] = C_BORD;
	color[17] = C_BRUN;
	color[18] = C_BLUEF;
	color[19] = C_GREY;
	color[20] = C_GREYA;
	color[21] = C_BROWN;
	color[22] = C_ORANGE;
	color[23] = C_MILITARY;
}

void			set_colors(int *color)
{
	static int	i;
	int			colors[NB_COLORMAX];

	set_tab_color(colors);
	i++;
	if (i == NB_COLORMAX)
		i = 0;
	*color = colors[i];
}

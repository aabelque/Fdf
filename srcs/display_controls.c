/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:50:24 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/04 11:59:26 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		display_controls2(void)
{
	ft_putstr("\
__________________________\n\
CONTROLS:\n\
\n\
Quit:\n\
	KEY: ESC\n\
\n\
Color:\n\
	KEY: C\n\
__________________________\n\
");
}

char		*display_controls(void)
{
	char	*str;

	str = "\
CONTROLS: \n\
\n\
Quit-> \n\
	ESC \n\
\n\
Color-> \n\
	C\n\
";
	return (str);
}

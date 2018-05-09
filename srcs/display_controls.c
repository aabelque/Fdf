/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:50:24 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/09 12:46:29 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		display_controls2(void)
{
	ft_putstr("\
__________________________\n\
CONTROLS:\n\
Quit:\n\
	KEY: ESC\n\
\n\
Color:\n\
	KEY: C\n\
\n\
Rotation:\n\
	RotX: A,Q\n\
	RotY: D,E\n\
	RotZ: S,W\n\
\n\
Translation:\n\
	Left: Left Arrow\n\
	Right: Right Arrow\n\
	Up: Up Arrow\n\
	Down: Down Arrow\n\
\n\
Scale:\n\
	Widen: +\n\
	Narrow: -\n\
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

char		*display_controls3(void)
{
	char	*str;

	str = "\
CONTROLS: \n\
\n\
ROT-> \n\
	X:A,Q \n\
	Y:D,E \n\
	Z:S,W \n\
";
	return (str);
}

char		*display_controls4(void)
{
	char	*str;

	str = "\
CONTROLS: \n\
\n\
TRANSL-> \n\
	L, R, Up, Down Arrow\n\
";
	return (str);
}

char		*display_controls5(void)
{
	char	*str;

	str = "\
CONTROLS: \n\
\n\
SCALE-> \n\
	Widen: + \n\
	Narrow: -\n\
";
	return (str);
}

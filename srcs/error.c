/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:21:16 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/22 17:56:16 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			free_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void			ft_error_map(void)
{
	ft_putendl("map error");
	exit(1);
}

void			ft_error_malloc(void)
{
	ft_putendl("malloc error");
	exit(1);
}

int				ft_valid_map(t_env *e)
{
	int			i;
	static int	count;

	i = 0;
	while (e->map.line[i])
		i++;
	if (i == 0)
	{
		ft_putendl("invalid map");
		exit(1);
	}
	if (count == 0)
		count = i;
	if (count != i)
	{
		ft_putendl("invalid map");
		exit(1);
	}
	return (i);
}

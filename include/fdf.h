/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:39:53 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/23 17:45:47 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include <stdlib.h>

# define C_RED 0x00ff0000
# define C_GREEN 0x0000ff00
# define C_BLUE 0x000000ff

# define C_ABR 0x00e67e30
# define C_ACA 0x0088421d
# define C_AMA 0x0082C46C
# define C_AYELL 0x00f0C300
# define C_YELL 0x00ffff00
# define C_ARED 0x00ad360e
# define C_AUB 0x00370028
# define C_AZUR 0x001e7fCb
# define C_AZUR1 0x0074d0f1
# define C_CBLUE 0x00048b9a
# define C_LAV 0x009683eC
# define C_BORD 0x006d071a
# define C_BRUN 0x00Cd853f
# define C_BLUEF 0x00318Ce
# define C_WHITE 0x00fefefe
# define C_GREY 0x00606060
# define C_GREYA 0x00afafaf
# define C_BROWN 0x00582900
# define C_OLIV 0x00708d23
# define C_ORANGE 0x00ed7f10
# define C_MILITARY 0x00596643

# define X_WIN 2048
# define Y_WIN 1152
# define SCALE 20

typedef enum		e_key
{
	K_A = 0,
	K_S,
	K_D,
	K_W = 13,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
}					t_key;

typedef struct		s_img
{
	void			*img;
	int				*addr;
	int				bpp;
	int				s_line;
	int				endian;
}					t_img;

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef struct		s_map
{
	char			**line;
	int				nb_line;
	int				pt_line;
	int				points;
	int				len;
	t_list			*vector;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fd;
	int				ret;
	t_map			map;
	t_img			img;
}					t_env;

int					init_mlx(t_env *e);
int					loop_hook(t_env *e);
int					key_hook(int keycode, void *param);
void				print_vlist(t_list *vector);
void				create_vec(t_env *e, int j);
void				free_tab(char **tab);
void				error(char *str);
void				ft_error_map(void);
int					ft_valid_map(t_env *e);
void				ft_error_malloc(void);
void				parse_map(char **av, t_env *e);
int					ft_nb_line(char **av);
#endif

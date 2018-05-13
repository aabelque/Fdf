/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:39:53 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/13 18:40:52 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
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
# define C_AIM 0x0079f8f8
# define C_AZUR 0x001e7fCb
# define C_AZUR1 0x0074d0f1
# define C_CBLUE 0x00048b9a
# define C_LAV 0x009683eC
# define C_BORD 0x006d071a
# define C_BRUN 0x00Cd853f
# define C_BLUEF 0x00318Ce
# define C_GREY 0x00606060
# define C_GREYA 0x00afafaf
# define C_BROWN 0x00582900
# define C_OLIV 0x00708d23
# define C_ORANGE 0x00ed7f10
# define C_MILITARY 0x00596643
# define C_WHITE 0x00fefefe
# define C_BLACK 0x00000000

# define NB_COLORMAX 24

# define MOVXUP M_PI / 64
# define MOVXDO -M_PI / 64
# define MOVYUP M_PI / 64
# define MOVYDO -M_PI / 64
# define MOVZUP M_PI / 64
# define MOVZDO -M_PI / 64

# define TUP -50
# define TDO 50
# define TLEFT -50
# define TRIGHT 50

# define SPLUS 1.1
# define SLESS 0.9

# define X_WIN 2560
# define Y_WIN 1440
# define SCALE 15

typedef enum		e_key
{
	K_A = 0,
	K_COLORS = 8,
	K_W = 13,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP,
	K_ROTX = 0,
	K_ROTX2 = 12,
	K_ROTY = 2,
	K_ROTY2 = 14,
	K_ROTZ = 13,
	K_ROTZ2 = 1,
	K_SLESS = 78,
	K_SPLUS = 69,
	K_PERS = 35,
	K_V = 9,
	K_B = 11,
	K_G = 5
}					t_key;

typedef struct		s_img
{
	void			*img;
	int				*addr;
	int				bpp;
	int				s_line;
	int				endian;
}					t_img;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vec;

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_map
{
	char			**line;
	int				nb_line;
	int				pt_line;
	size_t			nb_v;
	int				points;
	int				len;
	t_vec			*vertex;
	t_list			*vector;
}					t_map;

typedef struct		s_matrice
{
	t_vec			a;
	t_vec			b;
}					t_matrice;

typedef struct		s_matransf
{
	t_vec			v1;
	t_vec			v2;
	t_vec			v3;
	t_vec			v4;
}					t_matransf;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fd;
	int				ret;
	int				i;
	int				color;
	int				color2;
	double			degx;
	double			degy;
	double			degz;
	double			dega;
	t_vec			center;
	t_matrice		mat;
	t_map			map;
	t_img			img;
}					t_env;

t_color				color_interp(int color1, int color2, double t);
void				set_colors(int *color);
void				set_colors2(int *color);
void				draw2(t_env *e);
void				draw(t_env *e);
void				*lst_to_array(t_list *vector);
void				bresenham(t_env *e, int *addr);
int					init_mlx(t_env *e);
int					loop_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				print_vlist(t_list *vector);
void				create_vec(t_env *e, int j);
void				free_tab(char **tab);
void				ft_error(char *str);
void				ft_error_map(void);
int					ft_valid_map(t_env *e);
void				ft_error_malloc(void);
void				parse_map(char **av, t_env *e);
int					ft_nb_line(char **av);
char				*display_controls(void);
char				*display_controls3(void);
char				*display_controls4(void);
char				*display_controls5(void);
void				display_controls2(void);
t_vec				newvec(double x, double y, double z, double w);
t_matransf			rotxmat(double deg);
t_matransf			rotymat(double deg);
t_matransf			rotzmat(double deg);
t_matransf			transl_mat(double x, double y, double z);
t_matransf			scal_mat(double s);
t_matransf			matrix_z(double z);
void				calculated_matrice(t_vec *m, t_matransf *mt, t_env *e);
void				matcal_rot(t_env *e, double deg, char axe);
void				matcal_transl(t_env *e, double x, double y, double z);
void				matcal_scal(t_env *e, double s);
void				redraw(t_env *e);
int					expose_hook(t_env *e);
void				get_center(t_env *e);
void				map_control(t_env *e);
int					out_map(t_vec *vertex);
void				apply_calmat(t_env *e, t_vec *m, t_matransf *mt);
void				apply_calmat2(t_env *e, t_vec *m, t_matransf *mt);
void				calculated_transl(t_vec *m, t_matransf *mt, t_env *e);
void				calculated_scal(t_vec *m, t_matransf *mt, t_env *e);
void				calculated_cav(t_vec *m, t_matransf *mt, t_env *e);
void				apply_calmat2(t_env *e, t_vec *m, t_matransf *mt);
void				apply_calmat3(t_env *e, t_vec *m, t_matransf *mt);
void				apply_calmat4(t_env *e, t_vec *m, t_matransf *mt);
double				rad_deg(double deg);
void				matcal_cav(t_env *e, double deg);
t_matransf			matrixcav(double deg);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:00:02 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:54:23 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 1920
# define HEIGHT 1080
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <time.h>
# include "get_next_line.h"

typedef struct	s_line
{
	char		**tab;
	int			rows;
	int			columns;
	int			helper;
	int			last;
}				t_line;

typedef struct	s_textures
{
	void		*mxpmno;
	void		*mxpmso;
	void		*mxpmwe;
	void		*mxpmea;
	void		*mxpmsp;
	int			*datadsp;
	int			*datadno;
	int			*datadso;
	int			*datadwe;
	int			*datadea;
	int			*datad;
	int			ss;
	int			aa;
	int			bb;
	float		o;
	int			x;
	int			xx;
	int			yy;
	float		wallheight;
	int			color;
	int			top;
	int			bot;
	float		fac;
	int			xo;
	int			k;
	float		yo;
}				t_textures;

typedef struct	s_character
{
	float		a;
	float		b;
	int			r;
	float		op;
	float		or;
	float		rx;
	float		ry;
	float		len;
}				t_character;

typedef struct	s_file
{
	int			width;
	int			height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	float		xposition;
	float		yposition;
	char		direction;
	int			color_f;
	int			color_c;
}				t_file;

typedef	struct	s_calcul
{
	int			tilesize;
	float		distance;
	int			top;
	int			bot;
	int			xx;
	float		x;
	float		y;
	float		wallheight;
	int			sprite;
}				t_calcul;

typedef	struct	s_bitmap
{
	int			pd_offset;
	int			header_size;
	int			image_width;
	int			image_height;
	int			bpp;
	int			width_in_bytes;
	int			planes;
	int			image_size;
	int			file_size;
}				t_bitmap;

typedef struct	s_sprite_info
{
	float		center_distance;
	float		intersec_distance;
	float		x;
	float		y;
	float		x_off;
}				t_sprite_info;

typedef struct	s_equation
{
	float		a;
	float		b;
	float		b1;
	int			helper;
}				t_equation;

typedef struct	s_s
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			tex;
	float		hx;
	float		hy;
	float		vx;
	float		vy;
	float		xxx;
	float		yyy;
	int			tilesize;
	int			up;
	int			down;
	int			vup;
	int			vdown;
	int			left;
	int			right;
	int			sprite;
	float		hxsprite;
	float		hysprite;
	float		vxsprite;
	float		vysprite;
	int			hlp_h;
	int			hlp_v;
	int			walk_right;
	int			walk_left;
	char		*file_name;
	char		*save;
	int			*n_sprites;
	int			ind;
	int			look;
	int			look_press;
	int			crouch;
	t_textures	*texture;
	t_character	*c;
	t_file		*file;
	t_line		*tab;
}				t_ii;

typedef struct	s_draw
{
	int			j;
	float		x;
	char		*line;
	int			fd;
	int			c;
	int			r;
	float		y;
	int			gnl;
	int			first;
}				t_dr;

typedef struct	s_hove
{
	float	xa;
	float	x;
	float	ya;
	float	y;
}				t_hv;

typedef struct	s_flag
{
	int			zero;
	int			minus;
	char		*width;
	char		*prec;
	char		conv;
	void		*arg;
	int			ford;
	int			salib;
	int			fors;
}				t_flag;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	struct	s_args
{
	char		*dcm;
	int			wdt;
	int			b;
	int			n;
	int			prec;
	int			z;
	int			forzero;
	int			zeros;
}				t_args;

typedef	struct	s_arg
{
	char		c;
	int			wdt;
	int			b;
	char		*m;
	char		chartoprint;
}				t_arg;

int				ft_atoi(char *str);
long long		ft_atoiu(char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *s);
int				ft_isdigit(int c);
void			ft_putstr(char *s);
char			*ft_substr(char const *s, int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_itoau(long long n);
char			*addchar(char *s1, char s2);
int				ft_putchar(char s, int l);
int				s(t_flag *flag);
int				u(t_flag *flag);
int				c(t_flag *flag);
int				xix(t_flag *flag);
int				di(t_flag *flag);
int				p(t_flag *flag);
int				expose(void *param);
char			*editstr(char *s1, int s, char s2, int l);
long long		convertu(long long n);
int				convert(int n);
char			*fill(int len, int n, char *p, int count);
int				whitespace(char c);
char			*fillwidth(const char *format, int *i,
va_list lst, t_flag *flag);
char			*fillprec(const char *format, int *i,
va_list lst, t_flag *flag);
int				fillzero(const char *format, int *i);
int				fillminus(const char *format, int *i);
char			fillconv(const char *format, int *i);
long long		negativeu(long long n);
char			*fillu(int len, long long n, char *p, int count);
int				ignore(const char *format, int *i);
void			initialise(t_flag *flag);
int				operations(t_flag *flag);
int				checkflags(const char *format, int *i, va_list lst);
int				ft_printf(const char *format, ...);
char			*hexadecimal(unsigned long long hex, char f);
void			flagg(t_flag *flag, const char *format,
int *i, va_list lst);
int				directions(t_ii *i);
int				drawfromfile(t_ii *i);
int				readfile(t_ii *i);
void			loopp(t_dr *d, t_ii *i);
int				down(t_ii *i, t_hv *v, float o);
void			up(t_ii *i, t_hv *v, float o);
void			right(t_ii *i, t_hv *v, float o);
void			left(t_ii *i, t_hv *v, float o);
void			draw_line(float x, float y, int len, float o, t_ii *i);
int				transform_color(int r, int g, int b);
void			sibagha(t_ii *i);
int				character(t_ii *i);
int				circle(t_ii *i);
void			drawwall(t_ii *i, t_calcul *calcul);
void			drawwfloor(t_ii *i, t_calcul *calcul);
void			drawcc(t_ii *i, t_calcul *calcul);
int				release(int key, void *param);
int				deal_key(int key, void *param);
void			update(t_ii *i);
void			noplayer(t_ii *i);
void			initials(t_ii *i);
void			initials2(t_ii *i);
float			direction(t_ii *i);
float			normalise(float o);
float			vertical(t_ii *i, float o);
float			vertical_sprite(t_ii *i, float o,
t_sprite_info *sprite_info, int x);
float			horizontal(t_ii *i, float o);
float			horizontal_sprite(t_ii *i, float o,
t_sprite_info *sprite_info, int x);
float			len(t_ii *i, float o);
float			distance_sprite(t_ii *i, float o,
t_sprite_info **sprite_info, int x);
void			getdata(t_ii *i, t_calcul *calcul);
void			inititialcalcul(t_calcul *calcul, t_ii *i);
void			draw_walls(t_ii *i);
void			draw_sprite(t_ii *i);
void			initialfile(t_ii *i);
void			error(t_ii *i, char *msg);
void			res(t_ii *i, char **line);
int				comma(t_ii *i, char **line, char c);
void			fcolor(t_ii *i, char **line);
void			ccolor(t_ii *i, char **line);
void			ntexture(t_ii *i, char **line);
void			stexture(t_ii *i, char **line);
void			weewtexture(t_ii *i, char **line);
void			readmap(t_ii *i, char **line);
void			distrub(t_ii *i, char **line);
void			everything(t_ii *i);
int				readfile(t_ii *i);
void			initialdr(t_dr *d, int l);
void			loopp(t_dr *d, t_ii *i);
void			lastline(t_dr *d, t_ii *i);
int				drawfromfile(t_ii *i);
double			linee(int x1, int y1, int x2, int y2, t_ii *i);
float			small_distance(t_ii *i, float o,
t_sprite_info **sprite_info, int x);
void			d_w_help(t_ii *i, t_calcul *calcul);
void			d_s_help(t_ii *i, t_calcul *calcul, t_sprite_info sprite_info);
void			draw_wall(t_ii *i);
float			check_ver(t_ii *i, float o);
float			check_hor(t_ii *i, float o);
int				s_itoa(int n);
int				create_bmp(t_ii *i);
void			color_to_rgb(int color, int *r, int *g, int *b);
int				release_help(int key, t_ii *i);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:25:30 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/27 18:53:57 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/minilibx_macos/mlx.h"
# include <math.h>



# include <stdio.h>



# define WDTH 800
# define HGHT 600

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tex;

typedef struct	s_ms
{
	char		*map_name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			**array;
	int			fd;
	char 		*name;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	int			Xmap;
	int			Ymap;
	int			Xstep;
	int			Ystep;
	int			hit;
	int			side;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			help;
	int			Xtext;
	int			Ytext;
	int			id;
	t_tex		tex[9];
	int			texture;
	int			x_floortext;
	int			y_floortext;
	int			x;
	int			y;
	int			map_lenght;
	double		Xpos;
	double		Ypos;
	double		Xdir;
	double		Ydir;
	double		Xplane;
	double		Yplane;
	double		Xcam;
	double		Xraypos;
	double		Yraypos;
	double		Xraydir;
	double		Yraydir;
	double		Xsidedist;
	double		Ysidedist;
	double		Xdeltadist;
	double		Ydeltadist;
	double		walldist;
	double		Xolddir;
	double		Xoldplane;
	double		ms;
	double		rs;
	double		Xwall;
}				t_ms;

void			draw_wall(int x, int start, int end, t_ms *ms);
void			put_pxl_to_img(t_ms *ms, int x, int y, int color);

int				key_press2(int keycode, t_ms *ms);
int				key_press(int keycode, t_ms *ms);
int				key_release(int keycode, t_ms *ms);
void			move_side(t_ms *ms);
int				move(t_ms *ms);

void			load_textures(t_ms *ms);
void			load_textures2(t_ms *ms, int a, int b);

void			mlx_win_init(t_ms *ms);
void			wolf3d_init(t_ms *ms);

int				check_map(char *buff, t_ms *ms);
void			ft_parser(t_ms *ms);

void			launch_wolf(t_ms *ms);
void			ray_casting_init(t_ms *ms, int x);
void			floor_and_ceiling(t_ms *ms, int x);
void			dda(t_ms *ms);
void			dda_init(t_ms *ms);
void			check_map_validity(t_ms *ms);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 12:20:02 by sflinois          #+#    #+#             */
/*   Updated: 2017/06/05 16:37:13 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
}				t_pixel;

typedef struct	s_line
{
	double		dx;
	double		sx;
	double		dy;
	double		sy;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_map
{
	int			max_x;
	int			max_y;
	int			max_z;
	int			mv_x;
	int			mv_y;
	t_vec4		**p;
}				t_map;

typedef struct	s_proj
{
	double		max_heigth;
	double		tile_wid;
	double		tile_len;
	double		half_tw;
	double		half_tl;
	double		max_len;
	double		min_len;
	double		max_wid;
	double		min_wid;
	double		space;
}				t_proj;

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			opp;
	int			sizeline;
	int			endian;
	int			color;
	int			color_v;
}				t_image;

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	int			w_maxx;
	int			w_maxy;
	short		enable_color;
	t_image		img;
	t_vec4		vec[2];
	t_map		map;
	t_map		map_s;
	t_proj		pj;
}				t_struct;

void			draw_line(t_struct *s);
void			draw_map(t_struct *s);
int			pars_args(char **argv, t_struct *s);
int			insert_in_map(int fd, t_map *map);
void			project_map(t_struct *s);
void			apply_proj(t_struct *s);
void			adapt_win(t_struct *s, t_proj *p);
void			center_map(t_struct *s);
void			reset_img(t_struct *s);
void			move_left(t_struct *s);
void			move_right(t_struct *s);
void			move_down(t_struct *s);
void			move_up(t_struct *s);
void			zoom_in(t_struct *s);
void			zoom_out(t_struct *s);
void			enable_colors(t_struct *s);

#endif

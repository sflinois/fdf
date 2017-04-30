/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 12:20:02 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/30 18:58:26 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_pixel
{
	int		x;
	int		y;
	int		z;
}				t_pixel;

typedef struct	s_line
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		err2;
}			t_line;

typedef struct	s_map
{
	int		max_x;
	int		max_y;
	int		max_z;
	t_pixel	**p;
}				t_map;

typedef struct	s_proj
{
	int		max_heigth;
	int		tile_wid;
	int		tile_len;
	int		half_tw;
	int		half_tl;
	int		max_len;
	int		min_len;
	int		max_wid;
	int		min_wid;
	int		space;
}				t_proj;

typedef struct	s_image
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		opp;
	int		sizeline;
	int		endian;
	int		color;
	int		color_v;
}				t_image;

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	int			w_maxx;
	int			w_maxy;
	t_image		img;
	t_pixel		pix[2];
	t_map		map;
}				t_struct;

void		draw_line(t_struct *s);
void		draw_map(t_struct *s);
int			pars_args(char **argv, t_struct *s);
void		apply_proj(t_struct *s);
#endif

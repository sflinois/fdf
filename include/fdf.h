/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 12:20:02 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/26 17:19:48 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_pixel
{
	int		x;
	int		y;
}				t_pixel;

typedef struct s_line
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		err2;
}			t_line;

typedef struct s_map
{
	int		max_x;
	int		max_y;
	int		max_z;
	int		**p;
}				t_map;

typedef struct	s_struct
{
	int			w_maxx;
	int			w_maxy;
	t_pixel		pixs[2];
	t_map		map;
}				t_struct;

void		draw_line(void *mlx, void *win, t_struct *s);
void		draw_map(void *mlx, void *win, t_struct *s);
int			pars_args(char **argv, t_struct *s);
#endif

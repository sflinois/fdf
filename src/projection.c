/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:45:32 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/29 16:13:29 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/includes/libft.h"

void	adapt_win(t_struct *s, t_proj *p)
{
	int		x;
	int		y;
	int		cst_x;
	int		cst_y;

	cst_x = p->min_len - p->space;
	cst_y = p->min_wid - p->space;
	s->w_maxx = p->max_len - cst_x + p->space;
	s->w_maxy = p->max_wid - cst_y + p->space;
	y = 0;
	while (y < s->map.max_y)
	{
		x = 0;
		while (x < s->map.max_x)
		{
			s->map.p[y][x].x -= cst_x;
			s->map.p[y][x].y -= cst_y;
			x++;
		}
		y++;
	}
}

void	apply_proj(t_struct *s)
{
	t_proj	p;
	int		x;
	int		y;
	float	calc_z;

	s->w_maxx = 1400;
	s->w_maxy = 800;
	p.max_heigth = 50; //50
	p.tile_wid = 80; //80
	p.tile_len = 30; //30
	p.half_tw = p.tile_wid / 2;
	p.half_tl = p.tile_len / 2;
	p.max_len = 0;
	p.min_len = 0;
	p.max_wid = 0;
	p.min_wid = 0;
	p.space = 20;
	y = 0;
	while (y < s->map.max_y)
	{
		x = 0;
		while (x < s->map.max_x)
		{
			calc_z = s->map.max_z != 0 ?
				(s->map.p[y][x].z / s->map.max_z) * p.max_heigth
				: (s->map.p[y][x].z) * p.max_heigth ;
			s->map.p[y][x].x = (x - y) * p.half_tw;
			s->map.p[y][x].y = (x + y) * p.half_tl - calc_z;
			if (s->map.p[y][x].x > p.max_len)
				p.max_len = s->map.p[y][x].x;
			if (s->map.p[y][x].x < p.min_len)
				p.min_len = s->map.p[y][x].x;
			if (s->map.p[y][x].y > p.max_wid)
				p.max_wid = s->map.p[y][x].y;
			if (s->map.p[y][x].y < p.min_wid)
				p.min_wid = s->map.p[y][x].y;
			x++;
		}
		y++;
	}
	adapt_win(s, &p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:45:32 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/14 17:03:36 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/includes/libft.h"

void	center_map(t_struct *s)
{
	int	mid_x;
	int	mid_y;
	int	modif_x;
	int	modif_y;
	int	x;
	int	y;

	mid_x = s->w_maxx / 2;
	mid_y = s->w_maxy / 2;
	x = s->map_s.max_x / 2;
	y = s->map_s.max_y / 2;
	modif_x = mid_x - s->map.p[y][x].v[0];
	modif_y = mid_y - s->map.p[y][x].v[1];
	y = 0;
	while (y < s->map.max_y)
	{
		x = 0;
		while (x < s->map.max_x)
		{
			s->map.p[y][x].v[0] += modif_x;
			s->map.p[y][x].v[1] += modif_y;
			x++;
		}
		y++;
	}
}
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
			s->map.p[y][x].v[0] -= cst_x;
			s->map.p[y][x].v[1] -= cst_y;
			x++;
		}
		y++;
	}
}

int		adapt_size(t_struct *s, t_proj *p, t_map map)
{
	if (p->max_len == 0 && s->map.max_x > 0)
		return (0);
	if (p->max_len - p->min_len > s->w_maxx || p->max_wid - p->min_wid > s->w_maxy)
	{
		if (p->max_heigth > s->map.max_z + 1)
			p->max_heigth -= 1;
		if (p->tile_wid > 8)
			p->tile_wid -= 2;
		else
			return (1);
		if (p->tile_len > 4)
			p->tile_len -= 1;
		else
			return(1);
		s->map = map;
		p->half_tw = p->tile_wid / 2;
		p->half_tl = p->tile_len / 2;
		return (0);
	}
	return (1);
}

void	project_map(t_struct *s)
{
	int		x;
	int		y;
	float	calc_z;

	y = 0;
	while (y < s->map.max_y)
	{
		x = 0;
		while (x < s->map.max_x)
		{
			if (s->map.p[y][x].v[0] == s->pj.max_len)
				s->pj.max_len = s->pj.min_len;
			if (s->map.p[y][x].v[0] == s->pj.min_len)
				s->pj.min_len = s->pj.max_len;
			if (s->map.p[y][x].v[1] == s->pj.max_wid)
				s->pj.max_wid = s->pj.min_wid;
			if (s->map.p[y][x].v[1] == s->pj.min_wid)
				s->pj.min_wid = s->pj.max_wid;
			calc_z = s->map.max_z != 0 ?
				(s->map.p[y][x].v[2]) * s->pj.max_heigth
				: (s->map.p[y][x].v[2]) * s->pj.max_heigth ;
			//modif Y en le multipliant pour changer l'angle ?
			s->map.p[y][x].v[0] = (x - y) * s->pj.half_tw;
			s->map.p[y][x].v[1] = (x + y) * s->pj.half_tl - calc_z;
			if (s->map.p[y][x].v[0] > s->pj.max_len)
				s->pj.max_len = s->map.p[y][x].v[0];
			if (s->map.p[y][x].v[0] < s->pj.min_len)
				s->pj.min_len = s->map.p[y][x].v[0];
			if (s->map.p[y][x].v[1] > s->pj.max_wid)
				s->pj.max_wid = s->map.p[y][x].v[1];
			if (s->map.p[y][x].v[1] < s->pj.min_wid)
				s->pj.min_wid = s->map.p[y][x].v[1];
			x++;
		}
		y++;
	}
}
void	apply_proj(t_struct *s)
{

	s->w_maxx = 1500;
	s->w_maxy = 700;
	s->pj.max_heigth = 1; //50
	s->pj.tile_wid = 80; //80
	s->pj.tile_len = 40; //30
	s->pj.half_tw = s->pj.tile_wid / 2;
	s->pj.half_tl = s->pj.tile_len / 2;
	s->pj.max_len = 0;
	s->pj.min_len = 0;
	s->pj.max_wid = 0;
	s->pj.min_wid = 0;
	s->pj.space = 20;
	while (!adapt_size(s, &(s->pj), s->map_s))
		project_map(s);
	//adapt_win a modif, rédiut les cases plutot que la fenetre 
	adapt_win(s, &(s->pj));
}

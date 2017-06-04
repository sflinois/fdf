/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_fct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:25:20 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/15 16:25:46 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/mlx.h"

void	zoom_in(t_struct *s)
{
	if (s->pj.max_heigth * s->map.max_z < 5000 && s->pj.tile_len * s->map.max_x
			< 20000 && s->pj.tile_wid * s->map.max_y < 40000)
	{
		s->pj.max_heigth *= 2;
		s->pj.tile_len *= 2;
		s->pj.tile_wid *= 2;
		s->pj.half_tw = s->pj.tile_wid / 2;
		s->pj.half_tl = s->pj.tile_len / 2;
		project_map(s);
		center_map(s);
		reset_img(s);
		draw_map(s);
	}
}

void	zoom_out(t_struct *s)
{
	if (s->pj.max_heigth > 1 && s->pj.tile_len > 4 && s->pj.tile_wid > 8)
	{
		s->pj.max_heigth /= 2;
		s->pj.tile_len /= 2;
		s->pj.tile_wid /= 2;
		s->pj.half_tw = s->pj.tile_wid / 2;
		s->pj.half_tl = s->pj.tile_len / 2;
		project_map(s);
		center_map(s);
		reset_img(s);
		draw_map(s);
	}
}

void	enable_colors(t_struct *s)
{
	s->enable_color = s->enable_color ? 0 : 1;
	reset_img(s);
	draw_map(s);
}

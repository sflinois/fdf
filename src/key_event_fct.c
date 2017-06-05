/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:24:52 by sflinois          #+#    #+#             */
/*   Updated: 2017/06/05 17:47:20 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/mlx.h"

void	reset_img(t_struct *s)
{
	mlx_destroy_image(s->mlx, s->img.ptr);
	s->img.data = 0;
}

void	move_left(t_struct *s)
{
	s->map.mv_x -= 10;
	reset_img(s);
	draw_map(s);
}

void	move_right(t_struct *s)
{
	s->map.mv_x += 10;
	reset_img(s);
	draw_map(s);
}

void	move_down(t_struct *s)
{
	s->map.mv_y += 10;
	reset_img(s);
	draw_map(s);
}

void	move_up(t_struct *s)
{
	s->map.mv_y -= 10;
	reset_img(s);
	draw_map(s);
}

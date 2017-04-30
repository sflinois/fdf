/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:50:45 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/30 18:58:28 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "../include/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <math.h>

// ! attention avec la fonction abs, a verifier sir utilisable ou pas !

void		init_line(t_line *line, t_pixel a, t_pixel b)
{
	line->dx = abs(b.x - a.x);
	line->sx = a.x < b.x ? 1 : -1;
	line->dy = abs(b.y - a.y);
	line->sy = a.y < b.y ? 1 : -1;
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
}



void		draw_line(t_struct *s)
{
	t_line	line;

	init_line(&line, s->pix[0], s->pix[1]);
	mlx_pixel_put(s->mlx, s->win, s->pix[0].x, s->pix[0].y, 0xFFFFFF);
	// Le while est pas bon, remplacement du && par || !!!!!!!!
	while ((s->pix[0].x != s->pix[1].x) && (s->pix[0].y != s->pix[1].y))
	{
		line.err2 = line.err;
		if (line.err2 > -line.dx)
		{
			line.err -= line.dy;
			s->pix[0].x += line.sx;
		}
		if (line.err2 < line.dy)
		{
			line.err += line.dx;
			s->pix[0].y += line.sy;
		}
		if (s->pix[0].x > 0 && s->pix[0].x < s->w_maxx && s->pix[0].y > 0 &&
				s->pix[0].y < s->w_maxy)
			*(s->img.data + s->pix[0].y * s->img.sizeline + s->img.opp * s->pix[0].x)
				= s->img.color_v;
		//mlx_pixel_put(mlx, win, s->pix[0].x, s->pix[0].y, 0xFFFFFF);
	}
}

void		draw_map(t_struct *s)
{
	int		x;
	int		y;

	s->img.ptr = mlx_new_image(s->mlx, s->w_maxx, s->w_maxy);
	s->img.data = mlx_get_data_addr(s->img.ptr, &(s->img.bpp),
			&(s->img.sizeline), &(s->img.endian));
	s->img.color = 0x000000FFF;
	s->img.color_v = mlx_get_color_value(s->mlx, s->img.color);
	s->img.opp = s->img.bpp / 8;
	y = 0;
	while (y < s->map.max_y)
	{
		x = 0;
		while (x < s->map.max_x)
		{
			if (x + 1 < s->map.max_x)
			{
				s->pix[0] = s->map.p[y][x];
				s->pix[1] = s->map.p[y][x + 1];
				draw_line(s);
			}
			if (y + 1 < s->map.max_y)
			{
				s->pix[0] = s->map.p[y][x];
				s->pix[1] = s->map.p[y + 1][x];
				draw_line(s);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
}

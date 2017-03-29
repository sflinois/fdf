/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:50:45 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/29 15:40:29 by sflinois         ###   ########.fr       */
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

void		draw_line(void *mlx, void *win, t_struct *s)
{
	t_line	line;

	init_line(&line, s->pix[0], s->pix[1]);
	mlx_pixel_put(mlx, win, s->pix[0].x, s->pix[0].y, 0xFFFFFF);
	// Le while est pas bon, remplacement du && par || !!!!!!!!
	while ((s->pix[0].x != s->pix[1].x) || (s->pix[0].y != s->pix[1].y))
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
			mlx_pixel_put(mlx, win, s->pix[0].x, s->pix[0].y, 0xFFFFFF);
	}
}

void		draw_map(void *mlx, void *win, t_struct *s)
{
	int		x;
	int		y;
	int		t_s;

	t_s = 25;
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
				draw_line(mlx, win, s);
			}
			if (y + 1 < s->map.max_y)
			{
				s->pix[0] = s->map.p[y][x];
				s->pix[1] = s->map.p[y + 1][x];
				draw_line(mlx, win, s);
			}
			x++;
		}
		y++;
	}
}

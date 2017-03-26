/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:50:45 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/26 17:37:12 by sflinois         ###   ########.fr       */
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

	init_line(&line, s->pixs[0], s->pixs[1]);
	mlx_pixel_put(mlx, win, s->pixs[0].x, s->pixs[0].y, 0xFFFFFF);
	// Le while est pas bon, remplacement du && par || !!!!!!!!
	while ((s->pixs[0].x != s->pixs[1].x) || (s->pixs[0].y != s->pixs[1].y))
	{
	ft_printf("x0 x1 : %d %d y0 y1 : %d %d\n", s->pixs[0].x, s->pixs[1].x, s->pixs[0].y, s->pixs[1].y);
		line.err2 = line.err;
		if (line.err2 > -line.dx)
		{
			line.err -= line.dy;
			s->pixs[0].x += line.sx;
		}
		if (line.err2 < line.dy)
		{
			line.err += line.dx;
			s->pixs[0].y += line.sy;
		}
		if (s->pixs[0].x > 0 && s->pixs[0].x < s->w_maxx && s->pixs[0].y > 0 &&
				s->pixs[0].y < s->w_maxy)
			mlx_pixel_put(mlx, win, s->pixs[0].x, s->pixs[0].y, 0xFFFFFF);
	}
}

void		draw_map(void *mlx, void *win, t_struct *s)
{
	int		x;
	int		y;

	y = 0;
	while (y < s->map.max_y)
	{
		x = 0;
		while (x < s->map.max_x)
		{
			s->pixs[0].x = x * 50 + 10;
			s->pixs[0].y = y * 50 + 10;
			s->pixs[1].x = (x + 1) * 50 + 10;
			s->pixs[1].y = y * 50 + 10;
			draw_line(mlx, win, s);
			s->pixs[0].x = x * 50 + 10;
			s->pixs[0].y = y * 50 + 10;
			s->pixs[1].x = x * 50 + 10;
			s->pixs[1].y = (y + 1) * 50 + 10;
			draw_line(mlx, win, s);
			x++;
		}
		y++;
	}
}

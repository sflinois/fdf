/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:50:45 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/22 14:53:05 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "../include/fdf.h"

void		init_line(t_line *line, t_pixel a, t_pixel b)
{
	line->dx = b.x - a.x < 0 ? -(b.x - a.x) : b.x - a.x;
	line->sx = a.x < b.x ? 1 : -1;
	line->dy = b.y - a.y < 0 ? -(b.y - a.y) : b.y - a.y;
	line->sy = a.y < b.y ? 1 : -1;
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
}

void		draw_line(void *mlx, void *win, t_pixel a, t_pixel b)
{
	t_line	line;

	init_line(&line, a, b);
	mlx_pixel_put(mlx, win, a.x, a.y, 0xFFFFFF);
	while (a.x != b.x && a.y != b.y)
	{
		line.err2 = line.err;
		if (line.err2 > -line.dx)
		{
			line.err -= line.dy;
			a.x += line.sx;
		}
		if (line.err2 < line.dy)
		{
			line.err += line.dx;
			a.y += line.sy;
		}
		mlx_pixel_put(mlx, win, a.x, a.y, 0xFFFFFF);
	}
}

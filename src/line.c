/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:50:45 by sflinois          #+#    #+#             */
/*   Updated: 2017/06/05 18:53:48 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "../include/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <math.h>

void		init_line(t_line *line, t_vec4 a, t_vec4 b)
{
	line->dx = abs(b.v[0] - a.v[0]);
	line->sx = a.v[0] < b.v[0] ? 1 : -1;
	line->dy = abs(b.v[1] - a.v[1]);
	line->sy = a.v[1] < b.v[1] ? 1 : -1;
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
}

void		put_pixel(t_struct *s, int x, int y)
{
	int	i;

	s->img.color = 0xFF0000;
	if (!s->enable_color)
		s->img.color = 0xFFFFFF;
	else if (s->vec[0].v[2] < 0)
		s->img.color = 0x00FFFF;
	else if (s->vec[0].v[2] == 0 && s->vec[1].v[2] == 0)
		s->img.color = 0x00FF00;
	else if (s->vec[0].v[2] < s->map.max_z / 6
			&& s->vec[1].v[2] < s->map.max_z / 6)
		s->img.color = 0x00BB00;
	else if (s->vec[0].v[2] != s->vec[1].v[2])
		s->img.color = 0xFFFF00;
	else if (s->vec[0].v[2] != 0 && s->vec[0].v[2] == s->vec[1].v[2])
		s->img.color = 0xFFBB00;
	s->img.color_v = mlx_get_color_value(s->mlx, s->img.color);
	i = s->img.color_v;
	s->img.data[y * s->img.sizeline + s->img.opp * x] = i;
	if (s->img.opp > 1)
	{
		i = i >> 8;
		s->img.data[y * s->img.sizeline + s->img.opp * x + 1] = i;
	}
	if (s->img.opp > 2)
	{
		i = i >> 8;
		s->img.data[y * s->img.sizeline + s->img.opp * x + 2] = i;
	}
}

void		draw_line(t_struct *s)
{
	t_line	line;

	init_line(&line, s->vec[0], s->vec[1]);
	if (s->vec[0].v[0] > 0 && s->vec[0].v[0] < s->w_maxx &&
			s->vec[0].v[1] > 0 && s->vec[0].v[1] < s->w_maxy)
		put_pixel(s, s->vec[0].v[0], s->vec[0].v[1]);
	while ((s->vec[0].v[0] != s->vec[1].v[0]) ||
			(s->vec[0].v[1] != s->vec[1].v[1]))
	{
		line.err2 = line.err;
		if (line.err2 > -line.dx)
		{
			line.err -= line.dy;
			s->vec[0].v[0] += line.sx;
		}
		if (line.err2 < line.dy)
		{
			line.err += line.dx;
			s->vec[0].v[1] += line.sy;
		}
		if (s->vec[0].v[0] > 0 && s->vec[0].v[0] < s->w_maxx &&
				s->vec[0].v[1] > 0 && s->vec[0].v[1] < s->w_maxy)
			put_pixel(s, s->vec[0].v[0], s->vec[0].v[1]);
	}
}

void		draw_map(t_struct *s)
{
	int		x;
	int		y;

	s->img.ptr = mlx_new_image(s->mlx, s->w_maxx, s->w_maxy);
	s->img.data = mlx_get_data_addr(s->img.ptr, &(s->img.bpp),
			&(s->img.sizeline), &(s->img.endian));
	s->img.color = 0x00000FF0;
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
				s->vec[0] = s->map.p[y][x];
				s->vec[0].v[0] += s->map.mv_x;
				s->vec[0].v[1] += s->map.mv_y;
				s->vec[1] = s->map.p[y][x + 1];
				s->vec[1].v[0] += s->map.mv_x;
				s->vec[1].v[1] += s->map.mv_y;
				draw_line(s);
			}
			if (y + 1 < s->map.max_y)
			{
				s->vec[0] = s->map.p[y][x];
				s->vec[0].v[0] += s->map.mv_x;
				s->vec[0].v[1] += s->map.mv_y;
				s->vec[1] = s->map.p[y + 1][x];
				s->vec[1].v[0] += s->map.mv_x;
				s->vec[1].v[1] += s->map.mv_y;
				draw_line(s);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
	if (s->enable_help)
	{
		mlx_string_put(s->mlx, s->win, 10, 10, 0XFFFFFF, "Movement: Arrow Keys");
		mlx_string_put(s->mlx, s->win, 10, 30, 0XFFFFFF, "Zoom: +, -");
		mlx_string_put(s->mlx, s->win, 10, 50, 0XFFFFFF, "Heigth: PageUp, PageDown");
		mlx_string_put(s->mlx, s->win, 10, 70, 0XFFFFFF, "Colors: c");
		mlx_string_put(s->mlx, s->win, 10, 95, 0XFFFFFF, "Press 'h' to hide.");
	}
	else
		mlx_string_put(s->mlx, s->win, 5, 5, 0XFFFFFF, "Press \'h\' for help.");
}

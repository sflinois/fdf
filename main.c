/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 08:44:49 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/12 17:02:33 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../minilibx_macos/mlx.h"
#include "fdf.h"

int		bresenham_algo(void *mlx, void *win, t_pixel a, t_pixel b)
{
	int		zone;
	int		x;
	int		y;

	double	dx;
	double	dy;
	double	e;

	x = a.x;
	y = a.y;

	/*
	** Start strait and diagonal lines
	*/
	if (a.x == b.x)
	{
		if (a.y < b.y)
			while (y <= b.y)
				mlx_pixel_put(mlx, win, x, y++, 0xFFFFFF);
		else
			while (y >= b.y)
				mlx_pixel_put(mlx, win, x, y--, 0xFFFFFF);
		return (1);
	}
	if (a.y == b.y)
	{
		if (a.x < b.x)
			while (x <= b.x)
				mlx_pixel_put(mlx, win, x++, y, 0xFFFFFF);
		else
			while (x >= b.x)
				mlx_pixel_put(mlx, win, x--, y, 0xFFFFFF);
		return (1);
	}
	if (a.x - b.x == a.y - b.y)
	{
		if (a.x < b.x)
			while (x <= b.x)
				mlx_pixel_put(mlx, win, x++, y++, 0xFFFFFF);
		else
			while (x >= b.x)
				mlx_pixel_put(mlx, win, x--, y--, 0xFFFFFF);
		return (1);
	}
	if (a.x - b.x == b.y - a.y)
	{
		if (a.x < b.x)
			while (x <= b.x)
				mlx_pixel_put(mlx, win, x++, y--, 0xFFFFFF);
		else
			while (x >= b.x)
				mlx_pixel_put(mlx, win, x--, y++, 0xFFFFFF);
		return (1);
	}
	/*
	** end
	*/
	if ((dx = b.x - a.x) != 0)
	{
		if (dx > 0)
		{
			if ((dy = b.y - a.y) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						


					}


				}

			}
	
		}

	}
	return (1);
}

int		end_prog(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		end;
	t_pixel	a;
	t_pixel	b;

	a.x = 300;
	a.y = 30;
	b.x = 220;
	b.y = 330;
	end = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "fdf");
	bresenham_algo(mlx, win, a, b);	
	mlx_key_hook(win, end_prog, 0);
	if (end != 1)
		mlx_loop(mlx);
	return (0);
}

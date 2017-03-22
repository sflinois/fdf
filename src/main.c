/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 08:44:49 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/22 16:21:51 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/mlx.h"
#include "../include/fdf.h"

int		end_prog(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		end;
	t_pixel	a;
	t_pixel	b;

	if (argc != 2)
	{
		// modif des usages : price en compre de case_size et z_size (demo)
		printf("Usage : ./fdf <filename>\n");
		return (1);
	}
	if (pars_args(argv, &map) == -1)
	{
		printf("Found wrong line length. Exiting.\n");
		return (1);
	}

	argv = NULL;
	a.x = 200;
	a.y = 200;
	b.x = 200 - 20;
	b.y = 200 + 20;
	end = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "fdf");
	draw_line(mlx, win, a, b);
	mlx_key_hook(win, end_prog, 0);
	if (end != 1)
		mlx_loop(mlx);
	return (0);
}
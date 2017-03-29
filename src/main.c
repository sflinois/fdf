/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 08:44:49 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/29 13:40:00 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/mlx.h"
#include "../include/fdf.h"
#include "../libft/includes/libft.h"

int		end_prog(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_struct	s;
	int			ret;

	if (argc != 2)
	{
		// modif des usages : price en compre de case_size et z_size (demo)
		ft_printf("Usage : ./fdf <filename>\n");
		return (1);
	}
	ret = pars_args(argv, &s);
	if (ret == -1)
	{
		ft_printf("No file %s\n", argv[1]);
		return (1);
	}
	if (ret == -2)
	{
		ft_printf("No data found.\n");
		return (1);
	}
	if (ret == -3)
	{
		ft_printf("Found wrong line length. Exiting.\n");
		return (1);
	}
	apply_proj(&s);
	mlx = mlx_init();
	win = mlx_new_window(mlx, s.w_maxx, s.w_maxy, "fdf");
	draw_map(mlx, win, &s);
	mlx_key_hook(win, end_prog, 0);
	mlx_loop(mlx);
	return (0);
}

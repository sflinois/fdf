/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 08:44:49 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/30 19:36:09 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/mlx.h"
#include "../include/fdf.h"
#include "../libft/includes/libft.h"

int		gere_key_event(int keycode, void *param)
{
	t_struct	*s;

	s = (t_struct*)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 76)
	{
		s->img.opp++;
		draw_map(s);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_struct	s;
	int			ret;

	if (argc != 2)
	{
		// modif des usages : price en compre de case_size et z_size (demo)
		ft_printf("Usage : ./fdf <filename>\n");
		return (1);
	}
	ret = pars_args(argv, &s);
	if (ret < 0 )
	{
		if (ret == -1)
			ft_printf("No file %s\n", argv[1]);
		if (ret == -2)
			ft_printf("No data found.\n");
		if (ret == -3)
			ft_printf("Found wrong line length. Exiting.\n");
		return (1);
	}
	apply_proj(&s);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, s.w_maxx, s.w_maxy, "fdf");
	draw_map(&s);
	mlx_key_hook(s.win, gere_key_event, &s);
	mlx_loop(s.mlx);
	return (0);
}

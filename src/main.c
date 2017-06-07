/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 08:44:49 by sflinois          #+#    #+#             */
/*   Updated: 2017/06/05 19:18:25 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/mlx.h"
#include "../include/fdf.h"
#include "../libft/includes/libft.h"

void	init_struct(t_struct *s)
{
	s->map.max_x = 0;
	s->map.max_y = 0;
	s->map.max_z = 0;
	s->map.mv_x = 0;
	s->map.mv_y = 0;
	s->enable_color = 0;
	s->enable_help = 0;
}

int		gere_key_event(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		move_left((t_struct*)param);
	if (keycode == 124)
		move_right((t_struct*)param);
	if (keycode == 125)
		move_down((t_struct*)param);
	if (keycode == 126)
		move_up((t_struct*)param);
	if (keycode == 69)
		zoom_in((t_struct*)param);
	if (keycode == 78)
		zoom_out((t_struct*)param);
	if (keycode == 8)
		enable_colors((t_struct*)param);
	if (keycode == 4)
		enable_help((t_struct*)param);
	if (keycode == 116)
		add_heigth((t_struct*)param);
	if (keycode == 121)
		sub_heigth((t_struct*)param);
	return (0);
}

int		main(int argc, char **argv)
{
	t_struct	s;
	int			ret;

	init_struct(&s);
	ret = argc != 2 ? -5 : pars_args(argv, &s);
	if (ret < 0)
	{
		if (ret == -1)
			ft_printf("No file %s\n", argv[1]);
		if (ret == -2)
			ft_printf("No data found.\n");
		if (ret == -3)
			ft_printf("Found wrong line length. Exiting.\n");
		if (ret == -4)
			ft_printf("Unable to allocate memory. Exiting.\n");
		if (ret == -5)
			ft_printf("Usage : ./fdf <filename>\n");
		return (1);
	}
	apply_proj(&s);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, s.w_maxx, s.w_maxy, "fdf");
	draw_map(&s);
	mlx_do_key_autorepeaton(s.mlx);
	mlx_hook(s.win, 2, 0L, gere_key_event, &s);
	mlx_loop(s.mlx);
	return (0);
}

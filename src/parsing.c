/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:06:08 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/29 13:25:54 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		check_first_line_map(int fd, t_map *map)
{
	char	*str;
	int		i;

	if (get_next_line(fd, &str))
	{
		i = 0;
		while (str[i])
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i])
			{
				if (map->max_z < ft_atoi(str + i))
					map->max_z = ft_atoi(str + i);
				map->max_x++;
			}
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
		map->max_y++;
		free(str);
	}
	if (map->max_y == 0 || map->max_x == 0)
		return (-2);
	return (1);
}

int		check_lines_map(int fd, t_map *map)
{
	char	*str;
	int		i;
	int		x;

	while (get_next_line(fd, &str))
	{
		i = 0;
		x = 0;
		while (str[i])
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i])
			{
				if (map->max_z < ft_atoi(str + i))
					map->max_z = ft_atoi(str + i);
				x++;
			}
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
		map->max_y++;
		free(str);
		if (x < map->max_x)
			return (-3);
	}
	return (1);
}

int		insert_in_map(int fd, t_map *map)
{
	char	*str;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (get_next_line(fd, &str))
	{
		i = 0;
		x = 0;
		while (str[i] && x < map->max_x)
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i])
			{
				map->p[y][x].v[0] = x;
				map->p[y][x].v[1] = y;
				map->p[y][x].v[2] = ft_atoi(str + i);
				map->p[y][x].v[3] = 1;
			}
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			x++;
		}
		y++;
		free(str);
	}
	return (1);
}

int		pars_args(char **argv, t_struct *s)
{
	int		fd;
	int		i;
	int		ret;

	s->map.max_x = 0;
	s->map.max_y = 0;
	s->map.max_z = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if ((ret = check_first_line_map(fd, &s->map)) != 1)
		return (ret);
	if ((ret = check_lines_map(fd, &s->map)) != 1)
		return (ret);
	close(fd);
	i = 0;
	s->map.p = (vec4**)malloc(sizeof(vec4*) * s->map.max_y);
	while (i < s->map.max_y)
		s->map.p[i++] = (vec4*)malloc(sizeof(vec4) * s->map.max_x);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	insert_in_map(fd, &s->map);
	s->map_s = s->map;
	return (1);
}

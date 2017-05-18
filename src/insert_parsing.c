/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:59:39 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/15 17:03:06 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

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

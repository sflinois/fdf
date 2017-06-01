/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:59:39 by sflinois          #+#    #+#             */
/*   Updated: 2017/06/01 17:37:09 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

void	init_vec(t_vec4 *v, int x, int y, int z)
{
	(*v)[0] = x;
	(*v)[1] = y;
	(*v)[2] = z;
	(*v)[3] = 1;
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
				init_vec(&(map->p[y][x].v), x, y, ft_atoi(str + i));
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			x++;
		}
		y++;
		free(str);
	}
	return (1);
}

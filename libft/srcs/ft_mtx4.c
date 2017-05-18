/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 16:17:10 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/15 16:22:36 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

mtx4		ft_mtx4_multmtx(mtx4 a, mtx4 b)
{
	mtx4	ret;
	int		y;
	int		x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ret.m[y][x] = (a.m[y][0] * b.m[0][x]) + (a.m[y][1] * b.m[1][x])
				+ (a.m[y][2] * b.m[2][x]) + (a.m[y][3] * b.m[3][x]);
			x++;
		}
		y++;
	}
	return (ret);
}

vec4		ft_mtx4_multvec(mtx4 m, vec4 v)
{
	vec4	ret;
	int		y;

	y = 0;
	while (y < 4)
	{
		ret.v[y] = (m.m[y][0] * v.v[0]) + (m.m[y][1] * v.v[1])
			+ (m.m[y][2] * v.v[2]) + (m.m[y][3] * v.v[3]);
		y++;
	}
	return (ret);
}

mtx4		ft_mtx4_multnb(int i, mtx4 m)
{
	mtx4	ret;
	int		y;
	int		x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ret.m[y][x] = m.m[y][x] * i;
			x++;
		}
		y++;
	}
	return (ret);
}

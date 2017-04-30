/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 16:17:10 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/30 16:40:11 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

int		**ft_mtx4_multmtx(int **a, int **b)
{
	int		**ret;
	int		y;
	int		x;

	y = 0;
	if ((ret = (int**)malloc(sizeof(int*) * (4))))
		return (NULL);
	while (y < 4)
	{
		if ((ret[y] = (int*)malloc(sizeof(int) * (4))))
			return (NULL);
		x = 0;
		while (x < 4)
		{
			ret[y][x] = (a[y][0] * b[0][x]) + (a[y][1] * b[1][x])
				+ (a[y][2] * b[2][x]) + (a[y][3] * b[3][x]);
			x++;
		}
		y++;
	}
	return (ret);
}

int		**ft_mtx4_multvec(int **m, int **v)
{
	int		**ret;
	int		y;

	y = 0;
	if ((ret = (int**)malloc(sizeof(int*) * (4))))
		return (NULL);
	while (y < 4)
	{
		if ((ret[y] = (int*)malloc(sizeof(int))))
			return (NULL);
		ret[y][0] = (m[y][0] * v[0][0]) + (m[y][1] * v[1][0])
			+ (m[y][2] * v[2][0]) + (m[y][3] * v[3][0]);
		y++;
	}
	return (ret);
}

int		**ft_mtx4_multnb(int i, int **m)
{
	int		**ret;
	int		y;
	int		x;

	y = 0;
	if ((ret = (int**)malloc(sizeof(int*) * (4))))
		return (NULL);
	while (y < 4)
	{
		if ((ret[y] = (int*)malloc(sizeof(int) * (4))))
			return (NULL);
		x = 0;
		while (x < 4)
		{
			ret[y][x] = m[y][x] * i;
			x++;
		}
		y++;
	}
	return (ret);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 12:45:39 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/29 15:55:26 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_matrix	*ft_mtxnew(int nb_col, int nb_line, int **tab)
{
	t_matrix	*mtx;
	int			x;
	int			y;

	if (!(mtx = (t_matrix*)malloc(sizeof(t_matrix))))
		return (NULL);
	if ((mtx->m = (int**)malloc(sizeof(int*) * (nb_line))))
		return (NULL);
	mtx->nb_line = nb_line;
	mtx->nb_col = nb_col;
	y = 0;
	while (y < nb_line)
	{
		if (!(mtx->m[y] = (int*)malloc(sizeof(int) * (nb_col))))
			return (NULL);
		x = 0;
		while (x < nb_col)
		{
			mtx->m[y][x] = tab[y][x];
			x++;
		}
		y++;
	}
	return (mtx);
}

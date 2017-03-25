/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:52:55 by sflinois          #+#    #+#             */
/*   Updated: 2017/02/23 17:44:58 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strsplit_first(char **str, char c)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	if (!str || !(*str))
		return (NULL);
	while ((*str)[i] && (*str)[i] != c)
		i++;
	if ((*str)[i])
	{
		if (!(ret = strndup(*str, i)))
			return (NULL);
		if ((tmp = ft_strdup(*str + i + 1)))
		{
			free(*str);
			*str = ft_strdup(tmp);
			free(tmp);
		}
		return (ret);
	}
	return (NULL);
}

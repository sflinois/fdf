/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:40:26 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (!(*little))
		return ((char*)big);
	while (big[i] && len > 0)
	{
		while (big[i + j] == little[j] && (len - j) > 0)
		{
			if (!(little[j]))
				return ((char *)(big + i));
			j++;
		}
		if (!(little[j]))
			return ((char *)(big + i));
		j = 0;
		len--;
		i++;
	}
	return (NULL);
}

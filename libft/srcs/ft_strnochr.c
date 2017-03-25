/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnochr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:39:38 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/24 16:57:53 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strnochr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i++])
		if (s[i - 1] != (char)c)
			return ((char *)(s + i - 1));
	if (s[i - 1] != (char)c)
		return ((char *)(s + i - 1));
	return (NULL);
}

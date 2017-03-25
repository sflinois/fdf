/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:59:03 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdlib.h>

unsigned int	ft_strnbw(char const *s, char c)
{
	int		i;
	int		nbw;

	if (!s)
		return (0);
	i = 0;
	nbw = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			nbw++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nbw);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**ret;
	unsigned int		nb_w;
	unsigned int		start;
	size_t				len;

	nb_w = 0;
	start = 0;
	len = 0;
	if (!(ret = (char**)malloc(sizeof(char*) * (ft_strnbw(s, c) + 1))) || !s)
		return (NULL);
	ret[ft_strnbw(s, c)] = NULL;
	while (s[start])
	{
		while (s[start] == c && s[start])
			start++;
		while (s[start + len] != c && s[start + len])
			len++;
		if (s[start])
			if (!(ret[nb_w] = ft_strsub(s, start, len)))
				return (NULL);
		nb_w++;
		start += len;
		len = 0;
	}
	return (ret);
}

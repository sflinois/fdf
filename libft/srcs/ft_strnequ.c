/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:05:29 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	if (*s2 == '\0' || n == 0)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i < n)
		return ((s1[i] == s2[i]) ? 1 : 0);
	return ((s1[i - 1] == s2[i - 1]) ? 1 : 0);
}

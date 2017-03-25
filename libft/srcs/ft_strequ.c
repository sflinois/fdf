/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:58:58 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 == NULL)
		return (0);
	if (s2 == NULL)
		return (1);
	i = 0;
	if (*s2 == '\0')
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((s1[i] == s2[i]) ? 1 : 0);
}

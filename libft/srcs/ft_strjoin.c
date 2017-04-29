/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:16:35 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/19 11:23:25 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size1;
	unsigned int	size2;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	str[size1 + size2] = '\0';
	while (size2-- > 0)
		str[size1 + size2] = s2[size2];
	while (size1-- > 0)
		str[size1] = s1[size1];
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int	size1;
	unsigned int	size2;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	str[size1 + size2] = '\0';
	while (size2-- > 0)
		str[size1 + size2] = s2[size2];
	while (size1-- > 0)
		str[size1] = s1[size1];
	free(s1);
	free(s2);
	return (str);
}

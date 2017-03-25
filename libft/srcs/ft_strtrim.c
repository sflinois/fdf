/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:29:54 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		size;
	char	*str;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[size] == ' ' || s[size] == '\n' || s[size] == '\t') && size >= i)
		size--;
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1 - i + 1))))
		return (NULL);
	str = ret;
	while (i <= size)
	{
		*str = s[i];
		str++;
		i++;
	}
	*str = '\0';
	return (ret);
}

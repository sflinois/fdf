/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:11:41 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/18 16:40:23 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "../includes/libft.h"

char	*ft_retnwstr(wchar_t *wstr, size_t size)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;

	if (!wstr)
		return (NULL);
	ret = ft_strdup("");
	while (*wstr)
	{
		tmp = ret;
		tmp2 = ft_retwchar(*wstr);
		if (ft_strlen(tmp) + ft_strlen(tmp2) > size)
		{
			free(tmp2);
			return (tmp);
		}
		ret = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		wstr++;
	}
	return (ret);
}

size_t	ft_wstrlen(wchar_t *wstr)
{
	size_t	len;

	len = 0;
	while (wstr[len])
		len++;
	return (len);
}

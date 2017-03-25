/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:57:11 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/18 17:29:23 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "../includes/libft.h"

char	*ft_retwstr(wchar_t *wstr)
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
		ret = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		wstr++;
	}
	return (ret);
}

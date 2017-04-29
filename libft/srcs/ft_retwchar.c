/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:49:26 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/19 12:24:21 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "../includes/libft.h"
#include <inttypes.h>

static char		*four_byte_char(wchar_t wc, char *ret)
{
	*(ret + 3) = 256 + (127 & wc);
	wc = wc >> 6;
	*(ret + 2) = 256 + (127 & wc);
	wc = wc >> 6;
	*(ret + 1) = 256 + (127 & wc);
	wc = wc >> 6;
	*(ret) = 128 + 64 + 32 + 16 + (7 & wc);
	return (ret);
}

static char		*mult_byte_char(wchar_t wc, char *ret)
{
	if (wc >= 128 && wc < 2048)
	{
		*(ret + 1) = 128 + (63 & wc);
		wc = wc >> 6;
		*(ret) = 128 + 64 + (31 & wc);
		return (ret);
	}
	else if (wc >= 2048 && wc < 65536)
	{
		*(ret + 2) = 128 + (63 & wc);
		wc = wc >> 6;
		*(ret + 1) = 128 + (63 & wc);
		wc = wc >> 6;
		*(ret) = 128 + 64 + 32 + (15 & wc);
		return (ret);
	}
	else if (wc >= 65536 && wc < 2097152)
		return (four_byte_char(wc, ret));
	return (NULL);
}

size_t			ft_wcharlen(wchar_t wc)
{
	size_t		size;

	size = 0;
	if (wc >= 0 && wc < 128 && MB_CUR_MAX > 0)
		size = 1;
	else if (wc >= 128 && wc < 2048 && MB_CUR_MAX > 1)
		size = 2;
	else if (wc >= 2048 && wc < 65536 && MB_CUR_MAX > 2)
		size = 3;
	else if (wc >= 65536 && wc < 2097152 && MB_CUR_MAX > 3)
		size = 4;
	return (size);
}

char			*ft_retwchar(wchar_t wc)
{
	char		*ret;
	size_t		size;

	if (!(size = ft_wcharlen(wc)))
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	*(ret + size) = 0;
	if (wc >= 0 && wc < 128)
	{
		*(ret) = wc;
		return (ret);
	}
	return (mult_byte_char(wc, ret));
}

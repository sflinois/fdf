/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imttoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:07:36 by sflinois          #+#    #+#             */
/*   Updated: 2017/02/23 17:43:14 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char	*ft_imttoa_base(uintmax_t n, unsigned int base, int maj)
{
	uintmax_t		nui;
	unsigned int	i;
	char			*str;

	i = 1;
	nui = n;
	while (nui > (base - 1))
	{
		nui /= base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	nui = n;
	while (nui > (base - 1))
	{
		str[i--] = ft_digit_to_char(nui % base, base, maj);
		nui /= base;
	}
	str[i] = ft_digit_to_char(nui, base, maj);
	return (str);
}

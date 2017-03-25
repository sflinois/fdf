/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:23:00 by sflinois          #+#    #+#             */
/*   Updated: 2017/02/23 17:45:30 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_sttoa_base(size_t n, unsigned int base, int maj)
{
	size_t		nui;
	size_t		i;
	char		*str;

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

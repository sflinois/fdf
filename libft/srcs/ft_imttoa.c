/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imttoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:07:24 by sflinois          #+#    #+#             */
/*   Updated: 2017/02/23 17:34:04 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char	*ft_imttoa(intmax_t n)
{
	uintmax_t		nui;
	unsigned int	i;
	char			*str;

	i = (n < 0) ? 2 : 1;
	nui = (n < 0) ? -n : n;
	while (nui > 9)
	{
		nui /= 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	nui = (n < 0) ? -n : n;
	if (n < 0)
		str[0] = '-';
	while (nui > 9)
	{
		str[i--] = nui % 10 + '0';
		nui /= 10;
	}
	str[i] = nui + '0';
	return (str);
}

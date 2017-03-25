/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:23:17 by sflinois          #+#    #+#             */
/*   Updated: 2017/02/23 17:33:30 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_ctoa(char n)
{
	unsigned char	nui;
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

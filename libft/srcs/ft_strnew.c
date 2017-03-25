/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:46:47 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/24 17:03:51 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(size + sizeof(char))))
		return (NULL);
	ft_bzero((void*)str, size + 1);
	return (str);
}

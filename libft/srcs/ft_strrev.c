/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:54:35 by sflinois          #+#    #+#             */
/*   Updated: 2017/02/23 17:44:47 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	ft_strrev(char *str)
{
	char	*tmp;
	int		i_str;
	int		i_tmp;

	if (str)
	{
		i_tmp = ft_strlen(str);
		i_str = 0;
		if (!(tmp = ft_strdup(str)))
			return ;
		while (i_tmp > 0)
		{
			i_tmp--;
			str[i_str] = tmp[i_tmp];
			i_str++;
		}
		str[i_str] = '\0';
		free(tmp);
	}
}

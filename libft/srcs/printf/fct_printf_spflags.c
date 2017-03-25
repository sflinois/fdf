/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_printf_spflags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:18:59 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/19 14:23:06 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"
#include <stdlib.h>

char	*spflags_return(char *str, char *c, int nb, int i)
{
	char	*ret;

	ret = str;
	if (nb == 0)
	{
		if (str[i])
		{
			ft_memmove(str + 1, str, i);
			str[0] = *c;
		}
		else
		{
			if (!(ret = ft_strjoin(c, str)))
				return (NULL);
			free(str);
		}
		return (ret);
	}
	if (str[nb - 1] == '0')
		str[0] = *c;
	else
		str[nb - 1] = *c;
	return (ret);
}

char	*applyflag_spaceplus(char *str, t_expr expr)
{
	int		nb;
	int		i;
	char	*c;

	if (!str || !ft_strchr("di", (int)expr.type))
		return (str);
	c = expr.flags & F_PLUS ? "+" : " ";
	if (str[0] == '0' && !str[1])
	{
		free(str);
		return (ft_strjoin(c, "0"));
	}
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i] == ' ')
		i++;
	nb = i;
	if (str[i] == '-')
		return (str);
	while (ft_isdigit(str[i]))
		i++;
	while (i - nb < expr.precision && nb > 0)
		nb--;
	return (spflags_return(str, c, nb, i));
}

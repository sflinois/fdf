/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_printf_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:47:25 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/20 15:43:38 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"
#include <stdlib.h>

char	*apply_precision_int(char *str, t_expr expr, char *ret)
{
	int		neg;
	int		i;

	if (*str == '0' && expr.precision == 0)
	{
		if (ft_strchr("oO", (int)expr.type) && (expr.flags & F_SHARP))
			return (str);
		free(str);
		return (ft_strdup(""));
	}
	neg = 0;
	if (*str == '-')
		neg = 1;
	if (ft_strlen(str) - neg >= (size_t)expr.precision)
		return (str);
	if (!(ret = ft_strnew(expr.precision + neg)))
		return (NULL);
	i = expr.precision - ft_strlen(str) + neg;
	ft_strcat(ret + i, str);
	free(str);
	while (i-- > 0)
		ret[i + neg] = '0';
	ret[0] = neg ? '-' : '0';
	return (ret);
}

char	*apply_precision(char *str, t_expr expr)
{
	char	*ret;

	ret = NULL;
	if (!str || expr.precision == -1)
		return (str);
	if (ft_strchr("dDiboOuUxX", (int)expr.type))
		return (apply_precision_int(str, expr, ret));
	return (str);
}

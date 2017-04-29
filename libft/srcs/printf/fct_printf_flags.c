/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_printf_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:38:09 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/29 15:37:05 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"
#include <stdlib.h>

char	*sharp_noalloc(char *str, t_expr expr, int hexa, int i)
{
	i--;
	if (*str == '0')
		i = hexa;
	str[i] = 'x';
	if (expr.type == 'X')
		str[i] = 'X';
	str[i - hexa] = '0';
	return (str);
}

char	*applyflag_sharp(char *str, t_expr expr)
{
	char	*ret;
	int		hexa;
	int		i;

	if (!str)
		return (NULL);
	if (!ft_strchr("oOxXp", (int)expr.type))
		return (str);
	i = 0;
	while (str[i] == ' ' || str[i] == '0')
		i++;
	if (!str[i] || str[i] == 'x')
		return (str);
	hexa = 0;
	if (ft_strchr("xXp", (int)expr.type))
		hexa = 1;
	if (i >= (1 + hexa))
		return (sharp_noalloc(str, expr, hexa, i));
	if (!(ret = ft_strnew(ft_strlen(str) + 1 + hexa)))
		return (NULL);
	*(ret + hexa) = expr.type == 'X' ? 'X' : 'x';
	*ret = '0';
	ret = ft_strcat(ret, str + i);
	free(str);
	return (ret);
}

char	*applyflag_zero(char *str, t_expr expr)
{
	int		i;

	if (!str || expr.flags & F_MINUS ||
			!ft_strchr("dDioOuUxXsc%", (int)expr.type))
		return (str);
	i = 0;
	while (str[i] && expr.precision == -1)
	{
		if (str[i] == ' ')
			str[i] = '0';
		if (str[i] == '-' && i > 0 && !ft_strchr("sc%", (int)expr.type))
		{
			str[0] = '-';
			str[i] = '0';
		}
		i++;
	}
	return (str);
}

char	*applyflag_minus(char *str)
{
	int		i;
	char	*tmp_str;
	char	*tmp_space;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ')
		i++;
	tmp_str = ft_strdup(str + i);
	tmp_space = ft_strndup(str, i);
	if (!tmp_str || !tmp_space)
		return (NULL);
	free(str);
	str = ft_strjoin(tmp_str, tmp_space);
	free(tmp_str);
	free(tmp_space);
	return (str);
}

char	*apply_flags(char *str, t_expr expr)
{
	if (expr.flags & F_ZERO)
		str = applyflag_zero(str, expr);
	if (expr.flags & F_SHARP)
		str = applyflag_sharp(str, expr);
	if (expr.flags & F_MINUS)
		str = applyflag_minus(str);
	if (expr.flags & F_PLUS || expr.flags & F_SPACE)
		str = applyflag_spaceplus(str, expr);
	return (str);
}

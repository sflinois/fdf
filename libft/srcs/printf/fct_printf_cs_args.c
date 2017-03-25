/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_printf_cs_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:51:31 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/25 13:51:33 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int				end_conv_c(t_expr expr, char *disp, int c, wint_t wc)
{
	int			ret;

	disp = apply_min_width(disp, expr);
	disp = apply_flags(disp, expr);
	if (!disp)
		return (-1);
	if (c == 0 && wc == 0 && expr.min_width >= 1)
		disp[ft_strlen(disp) - 1] = 0;
	if (c == 0 && wc == 0 && expr.flags & F_MINUS)
		ft_putchar(0);
	ft_putstr(disp);
	if (c == 0 && wc == 0 && !(expr.flags & F_MINUS))
		ft_putchar(0);
	ret = ft_strlen(disp);
	free(disp);
	return (c == 0 && wc == 0 ? 1 + ret : ret);
}

int				conv_c_arg(t_expr expr, va_list *args)
{
	int			c;
	wint_t		wc;
	char		*disp;

	c = 0;
	wc = 0;
	if (expr.type == 'c' && expr.length != L_L)
	{
		c = va_arg(*args, int);
		disp = ft_strnew(1);
		disp[0] = c;
	}
	else
	{
		wc = va_arg(*args, wint_t);
		disp = ft_retwchar((wchar_t)wc);
	}
	return (end_conv_c(expr, disp, c, wc));
}

int				conv_s_arg(t_expr expr, va_list *args)
{
	char		*s;
	wchar_t		*ws;
	char		*disp;

	if (expr.type == 's' && expr.length != L_L)
	{
		s = va_arg(*args, char*);
		if (s == NULL)
			disp = expr.precision != -1 ?
				ft_strndup("(null)", expr.precision) : ft_strdup("(null)");
		else
			disp = expr.precision != -1 ?
				ft_strndup(s, expr.precision) : ft_strdup(s);
	}
	else
	{
		ws = va_arg(*args, wchar_t*);
		if (ws == NULL)
			disp = expr.precision != -1 ?
				ft_strndup("(null)", expr.precision) : ft_strdup("(null)");
		else
			disp = expr.precision != -1 ?
				ft_retnwstr(ws, expr.precision) : ft_retwstr(ws);
	}
	return (end_conv(expr, disp));
}

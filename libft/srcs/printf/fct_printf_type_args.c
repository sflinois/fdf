/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_type_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:03:01 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/20 15:29:50 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <inttypes.h>
#include <wchar.h>
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int				end_conv(t_expr expr, char *disp)
{
	int		ret;

	if (expr.type != '%')
		disp = apply_precision(disp, expr);
	disp = apply_min_width(disp, expr);
	disp = apply_flags(disp, expr);
	if (!disp)
		return (-1);
	ft_putstr(disp);
	ret = ft_strlen(disp);
	free(disp);
	return (ret);
}

int				conv_int_arg(t_expr expr, va_list *args)
{
	char		*disp;
	intmax_t	imt;

	apply_length(&imt, expr, args);
	if (expr.type == 'd' || expr.type == 'i')
		disp = ft_imttoa(imt);
	if (expr.type == 'b')
		disp = ft_imttoa_base(imt, 2, 0);
	if (expr.type == 'o')
		disp = ft_imttoa_base(imt, 8, 0);
	if (expr.type == 'u')
		disp = ft_imttoa_base(imt, 10, 0);
	if (expr.type == 'x')
		disp = ft_imttoa_base(imt, 16, 0);
	if (expr.type == 'X')
		disp = ft_imttoa_base(imt, 16, 1);
	return (end_conv(expr, disp));
}

int				conv_dou_arg(t_expr expr, va_list *args)
{
	char		*disp;
	long int	i;

	i = va_arg(*args, long int);
	if (expr.type == 'D')
		disp = ft_imttoa(i);
	if (expr.type == 'O')
		disp = ft_imttoa_base(i, 8, 0);
	if (expr.type == 'U')
		disp = ft_imttoa_base(i, 10, 0);
	return (end_conv(expr, disp));
}

int				conv_p_arg(t_expr expr, va_list *args)
{
	char		*disp;
	void		*p;

	p = va_arg(*args, void*);
	if (p != 0)
	{
		disp = ft_imttoa_base((uintmax_t)p, 16, 0);
		expr.flags |= F_SHARP;
	}
	else
	{
		if (expr.precision == 0)
			disp = ft_strdup("0x");
		else
			disp = ft_strdup("0x0");
	}
	return (end_conv(expr, disp));
}

int				conv_pct_arg(t_expr expr, va_list *args)
{
	char		*disp;
	va_list		warning;

	va_copy(warning, *args);
	disp = ft_strdup("%");
	return (end_conv(expr, disp));
}

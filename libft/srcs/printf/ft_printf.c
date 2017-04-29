/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:41:55 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/29 12:25:59 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int		convert_arg(t_expr expr, va_list *args)
{
	static const t_conv	conv_tab[] = {
						{"bdiouxX", conv_int_arg},
						{"DOU", conv_dou_arg},
						{"cC", conv_c_arg},
						{"sS", conv_s_arg},
						{"p", conv_p_arg},
						{"%", conv_pct_arg},
						{NULL, NULL},
						};
	int					i;
	int					ret;

	i = 0;
	ret = -1;
	while (!ft_strchr(conv_tab[i].type, expr.type))
		i++;
	if (conv_tab[i].type)
		ret = conv_tab[i].conv(expr, args);
	return (ret);
}

int		expr_pars(char **format, t_expr *expr)
{
	while (**format && ft_strchr("#0-+ 123456789.hljz", (int)**format))
	{
		pars_flags(format, expr);
		pars_min_width(format, expr);
		pars_precision(format, expr);
		pars_length(format, expr);
	}
	return (1);
}

int		process_conv(va_list *args, char **format)
{
	t_expr	expr;
	int		ret;

	ret = 0;
	new_expr(&expr);
	if (**format == '%')
	{
		(*format)++;
		if (expr_pars(format, &expr) == -1)
			return (-1);
		if (**format && ft_strchr("sSpdDioOuUxXcC%", (int)**format))
		{
			expr.type = **format;
			ret = convert_arg(expr, args);
			if (**format)
				(*format)++;
		}
		else if (**format)
		{
			ft_putchar(**format);
			ret = 1;
			(*format)++;
		}
	}
	return (ret);
}

int		process_args(va_list *args, char *format)
{
	int		ret;
	int		check_ret;

	ret = 0;
	while (*format)
	{
		while (*format && *format != '%')
		{
			ft_putchar(*format);
			format++;
			ret++;
		}
		check_ret = process_conv(args, &format);
		if (check_ret == -1)
			return (-1);
		ret += check_ret;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = process_args(&args, (char*)format);
	va_end(args);
	return (ret);
}

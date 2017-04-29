/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_printf_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:13:08 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/20 18:19:57 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	pars_flags(char **format, t_expr *expr)
{
	while (**format && ft_strchr("#0-+ ", (int)**format))
	{
		if (**format == '#')
			expr->flags |= F_SHARP;
		if (**format == '0')
			expr->flags |= F_ZERO;
		if (**format == '-')
			expr->flags |= F_MINUS;
		if (**format == '+')
			expr->flags |= F_PLUS;
		if (**format == ' ')
			expr->flags |= F_SPACE;
		(*format)++;
	}
}

void	pars_min_width(char **format, t_expr *expr)
{
	while (**format && ft_isdigit((int)**format))
	{
		if (expr->min_width != 0)
			expr->min_width *= 10;
		expr->min_width += (int)**format - '0';
		(*format)++;
	}
}

void	pars_precision(char **format, t_expr *expr)
{
	if (**format && **format == '.')
	{
		expr->precision = 0;
		(*format)++;
		while (**format && ft_isdigit((int)**format))
		{
			if (expr->precision != 0)
				expr->precision *= 10;
			expr->precision += (int)**format - '0';
			(*format)++;
		}
	}
}

void	pars_length(char **format, t_expr *expr)
{
	if (**format && (ft_strchr("hljz", (int)**format)))
	{
		if (**format == 'h' && expr->length < 2)
		{
			if (*((*format) + 1) == 'h')
				expr->length = expr->length < L_HH ? L_HH : expr->length;
			else
				expr->length = expr->length < L_H ? L_H : expr->length;
			*format = *((*format) + 1) == 'h' ? (*format) + 1 : *format;
		}
		if (**format == 'l')
		{
			expr->length = expr->length < L_L ? L_L : expr->length;
			if (*((*format) + 1) == 'l')
			{
				expr->length = expr->length < L_LL ? L_LL : expr->length;
				(*format)++;
			}
		}
		if (**format == 'j')
			expr->length = expr->length < L_J ? L_J : expr->length;
		if (**format == 'z')
			expr->length = expr->length < L_Z ? L_Z : expr->length;
		(*format)++;
	}
}

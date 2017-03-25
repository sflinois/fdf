/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_printf_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:14 by sflinois          #+#    #+#             */
/*   Updated: 2017/03/19 12:45:32 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <inttypes.h>
#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

void			apply_uns_length(intmax_t *imt, t_expr expr, va_list *args)
{
	*imt = va_arg(*args, uintmax_t);
	if (expr.length == 0)
		*imt = (unsigned int)*imt;
	else if (expr.length == L_HH)
		*imt = (unsigned char)*imt;
	else if (expr.length == L_H)
		*imt = (unsigned short int)*imt;
	else if (expr.length == L_L)
		*imt = (unsigned long int)*imt;
	else if (expr.length == L_LL)
		*imt = (unsigned long long int)*imt;
	else if (expr.length == L_Z)
		*imt = (size_t)*imt;
}

void			apply_length(intmax_t *imt, t_expr expr, va_list *args)
{
	char		is_uns;

	is_uns = 0;
	if (ft_strchr("ouxX", expr.type))
		is_uns = 1;
	if (is_uns)
		apply_uns_length(imt, expr, args);
	else if (!is_uns)
	{
		*imt = va_arg(*args, intmax_t);
		if (expr.length == 0)
			*imt = (int)*imt;
		else if (expr.length == L_HH)
			*imt = (char)*imt;
		else if (expr.length == L_H)
			*imt = (short int)*imt;
		else if (expr.length == L_L)
			*imt = (long int)*imt;
		else if (expr.length == L_LL)
			*imt = (long long int)*imt;
		else if (expr.length == L_Z)
			*imt = (size_t)*imt;
	}
}

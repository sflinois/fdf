/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:24:30 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/29 12:04:51 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <inttypes.h>

/*
** Binary flags for printf flags
*/

# define F_SHARP	1
# define F_ZERO		2
# define F_MINUS	4
# define F_PLUS		8
# define F_SPACE	16

/*
** Binary flags for printf length modifier
*/

# define L_HH		1
# define L_H		2
# define L_L		4
# define L_LL		8
# define L_J		16
# define L_Z		32

typedef struct		s_expr
{
	unsigned char	flags;
	unsigned int	min_width;
	int				precision;
	unsigned char	length;
	char			type;
}					t_expr;

typedef struct		s_conv
{
	char			*type;
	int				(*conv)(t_expr expr, va_list *args);
}					t_conv;

typedef struct		s_len_modifier
{
	char			type;
	char			c;
	short int		si;
	int				i;
	long int		li;
	long long int	lli;
	intmax_t		im;
	size_t			st;
}					t_len_modifier;

char				*apply_min_width(char *str, t_expr expr);
char				*apply_precision(char *str, t_expr expr);
char				*applyflag_spaceplus(char *str, t_expr expr);
char				*apply_flags(char *str, t_expr expr);
void				apply_length(intmax_t *imt, t_expr expr, va_list *args);

void				new_expr(t_expr *expr);
int					convert_arg (t_expr expr, va_list *args);
int					expr_pars(char **format, t_expr *expr);
void				pars_flags(char **format, t_expr *expr);
void				pars_min_width(char **format, t_expr *expr);
void				pars_precision(char **format, t_expr *expr);
void				pars_length(char **format, t_expr *expr);
int					process_conv(va_list *args, char **format);
int					process_args(va_list *args, char *format);
int					conv_int_arg(t_expr expr, va_list *args);
int					conv_dou_arg(t_expr expr, va_list *args);
int					conv_c_arg(t_expr expr, va_list *args);
int					conv_s_arg(t_expr expr, va_list *args);
int					conv_p_arg(t_expr expr, va_list *args);
int					conv_pct_arg(t_expr expr, va_list *args);
int					end_conv(t_expr expr, char *disp);

#endif

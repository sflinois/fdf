/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base2dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:56:09 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_base2dec(int nb, int base)
{
	int		pow;
	int		ret;
	int		neg;

	pow = 0;
	ret = 0;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	if (base > 10 || base <= 0)
		return (0);
	if (nb < base)
		return (nb);
	while (nb >= base)
	{
		ret += nb % 10 * ft_pow(10, pow);
		pow++;
		nb /= 10;
	}
	if (neg)
		return (-ret);
	return (ret);
}

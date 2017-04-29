/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base2base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:14:43 by sflinois          #+#    #+#             */
/*   Updated: 2017/04/29 12:47:16 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_base2base(int nb, int base1, int base2)
{
	int		pow;
	int		ret;
	int		neg;

	pow = 0;
	ret = 0;
	neg = 0;
	if (base1 > 10 || base1 <= 0 || base2 > 10 || base2 <= 0)
		return (0);
	if (base1 != 10)
		nb = ft_base2dec(nb, base1);
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	while (nb)
	{
		ret += nb % base2 * ft_pow(10, pow++);
		nb /= base2;
	}
	if (neg)
		return (-ret);
	return (ret);
}

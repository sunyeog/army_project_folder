/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:22:14 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/09/03 20:13:13 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	extraction(unsigned int nb)
{
	long long int	x;
	int				y;
	unsigned int	res;
	int				cnt;

	cnt = 0;
	x = 1;
	while (x <= nb)
		x *= 10;
	while (x >= 10)
	{
		y = x / 10;
		res = nb % x;
		res = res / y;
		ft_putchar(res + '0');
		cnt++;
		x /= 10;
	}
	return (cnt);
}

int	ft_putnbr(int nb)
{
	int	cnt;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		cnt = 11;
	}
	else if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
		cnt = extraction(nb);
		cnt += 1;
	}
	else if (nb > 0)
		cnt = extraction(nb);
	else
	{
		ft_putchar('0');
		cnt = 1;
	}
	return (cnt);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	cnt;

	if (nb == 0)
	{
		ft_putchar('0');
		cnt = 1;
	}
	else
		cnt = extraction(nb);
	return (cnt);
}

int	type_d(va_list *ap)
{
	int	d;
	int	cnt;

	d = va_arg(*ap, int);
	cnt = ft_putnbr(d);
	return (cnt);
}

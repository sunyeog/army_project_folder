/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:25:08 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/09/05 18:57:59 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_hex(unsigned int res, int a)
{
	unsigned int	i;
	char			*hexa;
	int				cnt;

	if (a == 1)
		hexa = "0123456789abcdef";
	else if (a == 0)
		hexa = "0123456789ABCDEF";
	cnt = 0;
	if (res <= 0)
		return (cnt);
	else
	{
		i = res % 16;
		cnt++;
		cnt += int_hex(res / 16, a);
		ft_putchar(hexa[i]);
	}
	return (cnt);
}

int	type_x(va_list *ap)
{
	int	x;
	int	cnt;

	x = (unsigned int)va_arg(*ap, int);
	if (x != 0)
	{
		cnt = int_hex(x, 1);
		return (cnt);
	}
	else
	{
		ft_putchar('0');
		return (1);
	}
}

int	type_xu(va_list *ap)
{
	int	xu;
	int	cnt;

	xu = (unsigned int)va_arg(*ap, int);
	if (xu != 0)
	{
		cnt = int_hex(xu, 0);
		return (cnt);
	}
	else
	{
		ft_putchar('0');
		return (1);
	}
}

int	type_per(char a)
{
	ft_putchar(a);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:00:15 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/11/18 17:51:45 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

int	ft_form(const char *str, va_list *ap)
{
	int	i;

	i = 0;
	if (str[i + 1] == 'c')
		return (type_c(ap));
	else if (str[i + 1] == 's')
		return (type_s(ap));
	else if (str[i + 1] == 'p')
		return (type_p(ap));
	else if (str[i + 1] == 'd')
		return (type_d(ap));
	else if (str[i + 1] == 'i')
		return (type_d(ap));
	else if (str[i + 1] == 'u')
		return (type_u(ap));
	else if (str[i + 1] == 'x')
		return (type_x(ap));
	else if (str[i + 1] == 'X')
		return (type_xu(ap));
	else if (str[i + 1] == '%')
		return (type_per('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	int		temp;

	va_start(ap, str);
	cnt = 0;
	if (str == 0)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			temp = ft_form(str++, &ap);
			if (*str == 0 || temp == -1)
				return (-1);
			cnt += temp;
		}
		else
		{
			ft_putchar(*str);
			cnt++;
		}
		str++;
	}
	return (cnt);
}
/*
#include "ft_printf.h"

int main(void)
{
	int	x;

	ft_printf("%d", x = 10);
	return (0);
}*/

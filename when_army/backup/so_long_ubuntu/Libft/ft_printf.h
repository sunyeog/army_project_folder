/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:58:01 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/11/18 17:47:48 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(const char a);
void	ft_putstr(char *c);
int		ft_printf(const char *str, ...);
//int		ft_strlen(char *c);
int		type_c(va_list *ap);
int		type_s(va_list *ap);
int		type_p(va_list *ap);
int		unsigned_hex(unsigned long long res);
int		type_d(va_list *ap);
int		extraction(unsigned int nb);
int		ft_putnbr(int nb);
int		type_u(va_list *ap);
int		ft_putnbr_u(unsigned int nb);
int		int_hex(unsigned int res, int a);
int		type_x(va_list *ap);
int		type_xu(va_list *ap);
int		type_per(char a);

#endif

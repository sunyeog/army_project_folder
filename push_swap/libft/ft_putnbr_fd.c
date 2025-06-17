/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:01:01 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 19:28:53 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n / 10 == 0)
		c = n + '0';
	else
	{
		ft_putnbr_fd((unsigned int)n / 10, fd);
		c = (unsigned int)n % 10 + '0';
	}
	write(fd, &c, 1);
}

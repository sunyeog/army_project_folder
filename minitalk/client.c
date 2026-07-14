/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:41:34 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/04/23 13:29:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_num(char *s)
{
	int	i;

	i = 0;
	if (s[0] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	send_sig(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (400);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		return (1);
	if (is_num(av[1]) == 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	i = 0;
	while (av[2][i])
	{
		send_sig(pid, av[2][i]);
		i++;
	}
	send_sig(pid, av[2][i]);
	return (0);
}

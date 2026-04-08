/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:41:34 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/04/08 03:41:39 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_sig(pid_t pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (100);
		i++;
	}
}

int main(int ac, char **av)
{
	int	i;
	pid_t pid;

	if (ac != 3)
		return (1);
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_sig(pid, av[2][i]);
		i++;
	}
	send_sig(pid, av[2][i]);
	return (0);
}

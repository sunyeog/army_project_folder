/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:06:24 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/04/19 11:20:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	nothing(int sig)
{
	(void)sig;
}

void	send_sig(pid_t pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();	
		i++;
	}
}

int main(int ac, char **av)
{
	int	i;
	pid_t pid;
	struct sigaction sa;

	if (ac != 3)
		return (1);
	sa.sa_handler = nothing;
	i = 0;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_sig(pid, av[2][i]);
		i++;
	}
	send_sig(pid, av[2][i]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:42:07 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/04/23 13:32:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	combine_char(int sig, siginfo_t *info, void *x)
{
	static int		i;
	static char		c;
	static pid_t	s;

	(void)x;
	if (s != info -> si_pid)
	{
		i = 0;
		c = 0;
	}
	s = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid is : %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = combine_char;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

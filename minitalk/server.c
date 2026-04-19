/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:06:17 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/04/19 11:41:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void combine_char(int sig, siginfo_t *info, void *x)
{
	static int i;
	static char c;

	(void)x;
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
	usleep(500);
	kill(info -> si_pid, SIGUSR1);
}

int main()
{
	struct sigaction sa;

	ft_printf("%d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = combine_char;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause() ;
	return (0);
}
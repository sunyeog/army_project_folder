/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 13:36:53 by codespace         #+#    #+#             */
/*   Updated: 2026/04/07 14:23:10 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void combine_char(int sig)
{
	static int i;
	static char c;

	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int main()
{
	struct sigaction sa;

	ft_printf("%d\n", getpid());
	sa.sa_handler = combine_char;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL);
	while (1)
		pause() ;
	return (0);
}

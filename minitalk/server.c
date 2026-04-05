/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 13:36:53 by codespace         #+#    #+#             */
/*   Updated: 2026/04/05 14:50:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void combine_char(int sig)
{
	static int i;
	static char c;

	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int main()
{
	PID출력;
	struct sigaction sa;
	sa.sa_handler = combine_char;
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL);
	while (1)
		pause() ;
}

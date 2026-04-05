/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 13:36:53 by codespace         #+#    #+#             */
/*   Updated: 2026/04/05 14:20:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void combine_char(int sig)
{
	static int i;
	static char c;

	i = 0;
	c = 0;
	if (sig == 0)
	{
		i++;
		return ;
	}
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
	if 신호가 1이면
		sigaction(10,combine_char(1),NULL);
	else
		sigaction(12,combine_char(0),NULL);
	while (1)
		pause() ;
}

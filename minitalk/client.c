/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:25:00 by codespace         #+#    #+#             */
/*   Updated: 2026/04/06 14:09:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

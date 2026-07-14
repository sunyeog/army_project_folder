/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:06:24 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/04/23 13:28:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	nothing(int sig)
{
	(void)sig;
}

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
		pause();
		i++;
	}
}

int	check_pid(char *s)
{
	pid_t	pid;

	if (!is_num(s))
		return (0);
	pid = ft_atoi(s);
	if (pid <= 0 || kill(pid, 0) == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
		return (1);
	if (!check_pid(av[1]))
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	sa.sa_handler = nothing;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (av[2][i])
	{
		send_sig(pid, av[2][i]);
		i++;
	}
	send_sig(pid, av[2][i]);
	return (0);
}

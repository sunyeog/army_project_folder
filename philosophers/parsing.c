/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:00 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/09/07 15:04:06 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_range(int ac, char **av, t_data *data)
{
    int i;
    int ret;

    i = 2;
    ret = philo_atoi(av[1]);
    if (ret <= 0)
        return (-1);
    data -> nb_philo = ret;
    while (i < ac)
    {
        ret = philo_atoi(av[i]);
        if (ret == -1)
            return (-1);
        if (i == 2)
            data -> time_die = ret;
        else if (i == 3)
            data -> time_eat = ret;
        else if (i == 4)
            data -> time_sleep = ret;
        i++;
    }
    return (0);
}

int check_num(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if (av[i][0] == '\0')
            return (-1);
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int parsing(int ac, char **av, t_data *data)
{
    if (!(ac == 5 || ac == 6))
        return (-1);
    if (check_num(ac, av) == -1 || check_range(ac, av, data) == -1)
        return (-1);
	if (ac == 6)
        data->must_eat = philo_atoi(av[5]);
    else
		data->must_eat = -1;
    return (0);
}
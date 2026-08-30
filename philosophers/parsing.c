/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:00 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/08/30 19:56:03 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_range(int ac, char **av)
{
    int i;

    i = 1;
    if (philo_atoi(av[1]) == 0)
            return (-1);
    while (i < ac)
    {
        if (philo_atoi(av[i]) == -1)
            return (-1);
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

int parsing(int ac, char **av)
{
    if (!(ac == 5 || ac == 6))
        return (-1);
    if (check_num(ac, av) == -1 || check_range(ac, av) == -1)
        return (-1);
    return (0);
}
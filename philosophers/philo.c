/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/09/15 17:46:09 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    start_eat(t_philo *philo)
{
	long long start;

	start = get_ms();
    printf("%lld %d is eating\n", get_ms() - philo->data->start_time,philo->id);
	while (get_ms() - start < philo->data->time_eat)
		usleep(100);
}

void	start_sleep(t_philo *philo)
{
	long long start;

	start = get_ms();
    printf("%lld %d is sleeping\n", get_ms() - philo->data->start_time,philo->id);
	while (get_ms() - start < philo->data->time_sleep)
		usleep(100);
}

void	start_think(t_philo *philo)
{
	
}
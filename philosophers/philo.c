/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/09/30 15:56:24 by sunhnoh          ###   ########.fr       */
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
    printf("%lld %d is sleeping\n", get_ms() - philo->data->start_time, philo->id);
	while (get_ms() - start < philo->data->time_sleep)
		usleep(100);
}

void	start_think(t_philo *philo)
{
    printf("%lld %d is thinking\n", get_ms() - philo->data->start_time, philo->id);
}

void	*routine(void *ptr)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)ptr;
	while (i < 3)
	{
		start_eat(philo);
		start_sleep(philo);
		start_think(philo);
		i++;
	}
	return (0);
}
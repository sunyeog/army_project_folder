/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/10/23 13:56:10 by sunhnoh          ###   ########.fr       */
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

void	take_fork(pthread_mutex_t *mutex, t_philo *philo)
{
	long long start;

	start = philo->data->start_time;
	pthread_mutex_lock(mutex);
	printf("%lld %d has taken a fork\n", get_ms() - start, philo->id);
}

void	take_forks(t_philo *philo, int	def_left)
{
	if (philo->id % 2 == 1)
	{
		take_fork(&philo->data->mutex[def_left], philo);
		take_fork(&philo->data->mutex[philo->id-1], philo);
	}
	else
	{
		take_fork(&philo->data->mutex[philo->id-1], philo);
		take_fork(&philo->data->mutex[def_left], philo);
	}
}


void	*routine(void *ptr)
{
	int	i;
	int	def_left;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)ptr;
	if (philo->id == 1)
		def_left = philo->data->nb_philo - 1;
	else
		def_left = philo->id - 2;
	while (i < 3)
	{
		take_forks(philo, def_left);
		philo->last_meal = get_ms();//이거 mutex감싸기부터 시작. 또 init, destroy해야함. 감시자 만들면 그것도 마찬가지.
		start_eat(philo);
		pthread_mutex_unlock(&philo->data->mutex[def_left]);
		pthread_mutex_unlock(&philo->data->mutex[philo->id-1]);
		start_sleep(philo);
		start_think(philo);
		i++;
	}
	return (0);
}
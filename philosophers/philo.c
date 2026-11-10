/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/11/10 18:17:25 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	situ_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_die);
	if (philo->data->if_end == 1 || philo->data->if_end == 2)
	{
		pthread_mutex_unlock(&philo->data->mutex_die);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex_die);
	return (0);
}

void    start_eat(t_philo *philo)
{
	long long start;

	if (situ_end(philo) == 1)
		return ;
	start = get_ms();
    printf("%lld %d is eating\n", get_ms() - philo->data->start_time,philo->id);
	while (get_ms() - start < philo->data->time_eat)
		usleep(100);
}

int	start_sleep(t_philo *philo)
{
	long long start;

	if (situ_end(philo) == 1)
		return (1);
	start = get_ms();
    printf("%lld %d is sleeping\n", get_ms() - philo->data->start_time, philo->id);
	while (get_ms() - start < philo->data->time_sleep)
		usleep(100);
	return (0);
}

void	start_think(t_philo *philo)
{
	if (situ_end(philo) == 1)
		return ;
    printf("%lld %d is thinking\n", get_ms() - philo->data->start_time, philo->id);
}

void	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	long long start;

	start = philo->data->start_time;
	pthread_mutex_lock(fork);
	if (situ_end(philo) == 1)
		return ;
	printf("%lld %d has taken a fork\n", get_ms() - start, philo->id);
}

void	take_forks(t_philo *philo, int	def_left)
{
	if (philo->id % 2 == 1)
	{
		take_fork(&philo->data->fork[def_left], philo);
		take_fork(&philo->data->fork[philo->id-1], philo);
	}
	else
	{
		take_fork(&philo->data->fork[philo->id-1], philo);
		take_fork(&philo->data->fork[def_left], philo);
	}
}


void	*routine(void *ptr)
{
	int	i;
	int	def_left;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id == 1)
		def_left = philo->data->nb_philo - 1;
	else
		def_left = philo->id - 2;
	if (philo->how_eat == philo->data->must_eat)
		return (0);
	while (situ_end(philo) != 1)
	{
		take_forks(philo, def_left);
		pthread_mutex_lock(&philo->mutex);
		philo->last_meal = get_ms();
		pthread_mutex_unlock(&philo->mutex);
		start_eat(philo);
		philo->how_eat++;
		pthread_mutex_unlock(&philo->data->fork[def_left]);
		pthread_mutex_unlock(&philo->data->fork[philo->id-1]);
		if (start_sleep(philo) == 1)
			return (0);
		start_think(philo);
	}
	return (0);
}
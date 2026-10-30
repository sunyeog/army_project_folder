/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:07:50 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/10/30 21:57:04 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*set_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (philo == NULL)
		return (NULL);
	while (i < data->nb_philo)
	{
		philo[i].id = i+1;
		philo[i].data = data;
		i++;
	}
	return (philo);
}

int	set_fork(t_data *data)
{
	pthread_mutex_t *f;
	int		i;

	i = 0;
	f = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (f == NULL)
		return (0);
	data->fork = f;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (1);
}

void	set_mutex(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_init(&philo[i].mutex, NULL);
		philo[i].last_meal = philo[i].data->start_time;
		i++;
	}
}

void	monitoring(t_philo *philo, t_data *data)
{
	int	i;

	while(1)
	{
		i = 0;
		while (i < philo->data->nb_philo)
		{
			pthread_mutex_lock(&philo[i].mutex);
			if (get_ms() - philo[i].last_meal > data->time_die)
			{
				pthread_mutex_unlock(&philo[i].mutex);
				printf("%lld %d died\n", get_ms() - data->start_time, i + 1);
				return ;
			}
			pthread_mutex_unlock(&philo[i].mutex);
			i++;
			usleep(5);
		}
	}
}

void	exe_pthread(t_philo *philo, void *(*fp)(void *))
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, fp, &philo[i]);
		i++;
	}
	monitoring(philo, philo->data);
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	fork_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}

void	mutex_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_destroy(&philo[i].mutex);
		i++;
	}
	
}

void end_philo(t_philo *philo, t_data *data)
{
	fork_destroy(data);
	mutex_destroy(philo);
	free(philo);
	free(data->fork);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	data;
	void	*(*fp)(void *);

	if (parsing(ac, av, &data) == -1)
		return (0);
	fp = routine;
	if (set_fork(&data) == 0)
		return (0);
	philo = set_philo(&data);
	if (philo == NULL)
	{
		fork_destroy(&data);
		free(data.fork);
		return (0);
	}
	philo->data->start_time = get_ms();
	set_mutex(philo);
	exe_pthread(philo, fp);
	end_philo(philo, &data);
	return (0);
	
	// philo.id = 1;
	// fp = routine;
	// philo.data = &data;
    // if (parsing(ac, av, philo.data) == -1)
    //     return (1);
	// philo.data->start_time = get_ms();
	// pthread_create(&philo.thread, NULL, fp, &philo);
	// pthread_join(philo.thread, NULL); 인자 하나일때 테스트 코드
}
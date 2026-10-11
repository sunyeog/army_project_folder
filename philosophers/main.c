/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:07:50 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/10/10 23:46:35 by sunhnoh          ###   ########.fr       */
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

void	exe_pthread(t_philo *philo, void *(*fp)(void *))
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, fp, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	data;
	void	*(*fp)(void *);

	if (parsing(ac, av, &data) == -1)
		return (0);
	fp = routine;
	philo = set_philo(&data);
	if (philo == NULL)
		return (0);
	philo->data->start_time = get_ms();
	exe_pthread(philo, fp);
	free(philo);
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
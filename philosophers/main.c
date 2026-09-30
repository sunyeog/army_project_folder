/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:07:50 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/09/30 19:00:21 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*mal_philo(int nb_philo)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	if (philo == NULL)
		return (NULL);
	return (philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	data;
	void	*(*fp)(void *ptr);

	philo = mal_philo();
	// philo.id = 1;
	// fp = routine;
	// philo.data = &data;
    // if (parsing(ac, av, philo.data) == -1)
    //     return (1);
	// philo.data->start_time = get_ms();
	// pthread_create(&philo.thread, NULL, fp, &philo);
	// pthread_join(philo.thread, NULL);
}
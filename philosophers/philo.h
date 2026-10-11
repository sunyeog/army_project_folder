/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:14 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/10/11 11:23:16 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

int philo_atoi(char *str);

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_data
{
	int				nb_philo;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int	 			must_eat;
	long long		start_time;
	pthread_mutex_t	*mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

int check_range(int ac, char **av, t_data *data);
int check_num(int ac, char **av);
int parsing(int ac, char **av, t_data *data);
long long get_ms(void);
void    start_eat(t_philo *philo);
void	start_sleep(t_philo *philo);
void	start_think(t_philo *philo);
void	*routine(void *ptr);


#endif
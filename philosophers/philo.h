/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:08:14 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/09/15 17:45:20 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
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
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

int check_range(int ac, char **av, t_data *data);
int check_num(int ac, char **av);
int parsing(int ac, char **av, t_data *data);
long long get_ms(void);
void    start_eat(t_philo *philo);
void	start_sleep(t_philo *philo);
void	start_think(t_philo *philo);


#endif
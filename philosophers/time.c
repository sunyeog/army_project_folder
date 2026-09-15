/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:18:31 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/09/15 17:39:51 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_ms(void)
{
    struct timeval	tv;
    long long res;

    gettimeofday(&tv, NULL);
    res = (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
    return (res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:43:41 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 16:21:23 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	goto_bed(t_philo *philos)
{
	print_routine(philos, "%ld %d is sleeping\n");
	usleep(philos->rules->sleep);
}

void	go_eat(t_philo *philos)
{
	forklift(philos);
	philos->last_meal = ms_clock();
	print_routine(philos, "%ld %d is eating\n");
	usleep(philos->rules->famine);
	forkdrop(philos);
}

void	go_think(t_philo *philos)
{
	print_routine(philos, "%ld %d is thinking\n");
}

void	forklift(t_philo *philos)
{
	pthread_mutex_lock(philos->fork1);
	print_routine(philos, "%ld %d has taken a fork\n");
	pthread_mutex_lock(philos->fork2);
	print_routine(philos, "%ld %d has taken a fork\n");
}

void	forkdrop(t_philo *philos)
{
	pthread_mutex_unlock(philos->fork1);
	pthread_mutex_unlock(philos->fork2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:43:41 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 18:48:15 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	goto_bed(t_philo *philos)
{
	print_routine(philos, "%ld %d is sleeping\n");
	usleep(philos->rules->sleep);
}

bool	go_eat(t_philo *philos)
{
	if (forklift(philos))
		return (true);
	philos->last_meal = ms_clock();
	print_routine(philos, "%ld %d is eating\n");
	usleep(philos->rules->famine);
	forkdrop(philos);
	return (false);
}

void	go_think(t_philo *philos)
{
	print_routine(philos, "%ld %d is thinking\n");
	usleep(1000);
}

bool	forklift(t_philo *philos)
{
	if (philos->id % 2)
	{
		pthread_mutex_lock(philos->fork1);
		if (king_rat(philos) && !pthread_mutex_unlock(philos->fork1))
			return (true);
		print_routine(philos, "%ld %d has taken a fork\n");
		pthread_mutex_lock(philos->fork2);
		if (king_rat(philos) && !pthread_mutex_unlock(philos->fork2))
			return (true);
		print_routine(philos, "%ld %d has taken a fork\n");
		return (false);
	}
	pthread_mutex_lock(philos->fork2);
	if (king_rat(philos) && !pthread_mutex_unlock(philos->fork2))
		return (true);
	print_routine(philos, "%ld %d has taken a fork\n");
	pthread_mutex_lock(philos->fork1);
	if (king_rat(philos) && !pthread_mutex_unlock(philos->fork1))
		return (true);
	print_routine(philos, "%ld %d has taken a fork\n");
	return (false);
}

void	forkdrop(t_philo *philos)
{
	if (philos->id % 2)
	{
		pthread_mutex_unlock(philos->fork1);
		pthread_mutex_unlock(philos->fork2);
		return ;
	}
	pthread_mutex_unlock(philos->fork2);
	pthread_mutex_unlock(philos->fork1);
}

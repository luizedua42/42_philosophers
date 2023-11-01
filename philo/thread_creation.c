/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:15:28 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/01 18:07:22 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *i);

bool	thread_creation(t_philo *philo, long n_of_philos)
{
	long		i;
	pthread_t	thread[200];

	i = -1;
	while (++i < n_of_philos)
		pthread_create(&thread[i], NULL, routine, &philo[i]);
	i = -1;
	while (++i < n_of_philos)
		pthread_join(thread[i], NULL);
	return (true);
}

void	*routine(void *philo)
{
	printf("thread: %ld\n", (*(t_philo *)philo).philos);
	return (NULL);
}

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

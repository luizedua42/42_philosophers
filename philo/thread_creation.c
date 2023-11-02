/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:15:28 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:50 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *i);
time_t	get_time(void);
bool	mutex_creation(t_philo *philo, long n_of_philos);

bool	thread_creation(t_philo *philo, long n_of_philos)
{
	long		i;
	pthread_t	thread[200];

	mutex_creation(philo, n_of_philos);
	i = -1;
	while (++i < n_of_philos)
		pthread_create(&thread[i], NULL, dinner, &philo[i]);
	i = -1;
	while (++i < n_of_philos)
		pthread_join(thread[i], NULL);
	return (true);
}

void	*dinner(void *phi)
{
	t_philo *philo;
	
	philo = phi;
	philo->start_time = get_time(); // == 0
	while(1)
	{
		pthread_mutex_lock(philo->print);
		printf("%ld Philo%ld is sleeping.\n", get_time() - philo->start_time, philo->philos);
		usleep(philo->time_to_sleep);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(philo->print);
		printf("%ld Philo%ld is eating.\n", get_time() - philo->start_time, philo->philos);
		usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(philo->print);
		printf("%ld Philo%ld is thinking.\n", get_time() - philo->start_time, philo->philos);
		pthread_mutex_unlock(philo->print);
	}
	return (NULL);
}
// printf("time diff: %ld\n", get_time() - philo->start_time);

bool	mutex_creation(t_philo *philo, long n_of_philos)
{
	long	i;

	i = -1;
	philo->print = malloc(1 * sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->print, NULL);
	while (++i < n_of_philos)
		philo[i].print = philo->print;
	return (true);
}

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:28:48 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 18:45:04 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dinner(void *philo);
static int	lone_wolf(long death);
static void	mutex_creation(t_philo *philo, long nop);
static bool	create_threads(t_philo *philos, long nop);

int	main(int argc, char **argv)
{
	t_philo	philos[200];
	long	nop;
	long	tod;

	if (argc < 4 || argc > 6)
		return (EXIT_FAILURE);
	if (overflow_validation(ft_atol(argv[1]) < 0))
		return (EXIT_FAILURE);
	if (input_validation(argv[1]) == false || ft_atol(argv[1]) > 200)
		return (EXIT_FAILURE);
	nop = ft_atol(argv[1]);
	if (nop == 1)
	{
		tod = ft_atol(argv[2]);
		return (lone_wolf(tod));
	}
	if (!init_philo(philos, argv, nop) || !philo_validation(philos, nop))
		return (false);
	mutex_creation(philos, nop);
	create_threads(philos, nop);
	return (EXIT_SUCCESS);
}

static void	mutex_creation(t_philo *philo, long nop)
{
	long			i;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*m_death;

	i = -1;
	m_death = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(m_death, NULL);
	philo->rules->m_death = m_death;
	print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print, NULL);
	philo->rules->print = print;
	fork = malloc(nop * sizeof(pthread_mutex_t));
	while (++i < nop)
		pthread_mutex_init(&fork[i], NULL);
	i = -1;
	while (++i < nop)
	{
		philo[i].fork1 = &fork[i];
		philo[i].fork2 = &fork[(i + 1) % nop];
	}
}

static bool	create_threads(t_philo *philos, long nop)
{
	long		i;
	pthread_t	threads[200];

	i = -1;
	while (++i < nop)
		philos[i].start_time = ms_clock();
	i = -1;
	while (++i < nop)
		pthread_create(&threads[i], NULL, dinner, &philos[i]);
	i = -1;
	while (++i < nop)
		pthread_join(threads[i], NULL);
	i = -1;
	while (++i < nop)
		pthread_mutex_destroy(philos[i].fork1);
	pthread_mutex_destroy(philos->rules->m_death);
	pthread_mutex_destroy(philos->rules->print);
	free(philos->fork1);
	free(philos->rules->print);
	free(philos->rules->m_death);
	return (true);
}

static void	*dinner(void *philo)
{
	t_philo	*philos;

	philos = philo;
	philos->last_meal = philos->start_time;
	if (philos->id % 2)
		usleep(1000);
	pthread_mutex_lock(philos->rules->m_death);
	while (philos->n_of_meals-- && philos->rules->is_alive)
	{
		pthread_mutex_unlock(philos->rules->m_death);
		if (king_rat(philos))
			return (print_routine(philos, "%ld %d has died\n"));
		go_think(philos);
		if (king_rat(philos) || go_eat(philos))
			return (print_routine(philos, "%ld %d has died\n"));
		if (king_rat(philos))
			return (print_routine(philos, "%ld %d has died\n"));
		goto_bed(philos);
		pthread_mutex_lock(philos->rules->m_death);
	}
	pthread_mutex_unlock(philos->rules->m_death);
	return (NULL);
}

static int	lone_wolf(long death)
{
	time_t	start_time;

	start_time = ms_clock();
	printf("%ld 0 has taken a fork\n", ms_clock() - start_time);
	usleep(death * 1000);
	printf("%ld 0 has died\n", ms_clock() - start_time);
	return (EXIT_SUCCESS);
}

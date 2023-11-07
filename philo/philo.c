/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:28:48 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:52 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dinner(void *philo);
static void	mutex_creation(t_philo *philo, long nop);
static bool	create_threads(t_philo *philos, long nop);

int	main(int argc, char **argv)
{
	t_philo philos[200];
	long	nop;

	if (argc < 4 || argc > 6)
		return (EXIT_FAILURE);
	if(input_validation(argv[1]) == false || ft_atol(argv[1]) > 200)
		return (EXIT_FAILURE);
	nop = ft_atol(argv[1]);
	if(!init_philo(philos, argv, nop) || !philo_validation(philos, nop))
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

	i = -1;
	print = malloc(sizeof(pthread_mutex_t));
	philo->rules->print = print;
	fork = malloc(nop * sizeof(pthread_mutex_t));
	while(++i < nop)
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
		pthread_create(&threads[i], NULL, dinner, &philos[i]);
	i = -1;
	while (++i < nop)
		pthread_join(threads[i], NULL);
	return (true);
}

static void	*dinner(void *philo)
{
	t_philo *philos;

	philos = philo;
	philos->start_time = ms_clock();
	philos->last_meal = philos->start_time;
	if (philos->id % 2)
		usleep(1000);
	while (1)
	{
		if(king_rat(philos))
		{
			print_routine(philos, "%ld %d has died");
			return(NULL);
		}
		goto_bed(philos);
		if(king_rat(philos))
		{
			print_routine(philos, "%ld %d has died");
			return(NULL);
		}
		go_eat(philos);
		if(king_rat(philos))
		{
			print_routine(philos, "%ld %d has died");
			return(NULL);
		}
		go_think(philos);
	}
}

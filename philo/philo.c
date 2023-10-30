/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:10 by luizedua          #+#    #+#             */
/*   Updated: 2023/10/30 19:01:46 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philos(t_philo *philo, long i);

int	main(int argc, char **argv)
{
	t_philo	philo[200];
	long	i;
	long	n_of_philos;

	i = -1;
	if (argc < 4 || argc > 6)
		return (EXIT_FAILURE);
	if (input_validation(argv[1]) == false)
		return (EXIT_FAILURE);
	n_of_philos = ft_atol(argv[1]);
	while (i < n_of_philos)
		init_philo(&philo[++i], argv);
	return (EXIT_SUCCESS);
}

void	print_philos(t_philo *philo, long i)
{
	printf("philo [%ld]die: %ld\n", i, philo->time_to_die);
	printf("philo [%ld]eat: %ld\n", i, philo->time_to_eat);
	printf("philo [%ld]sleep: %ld\n", i, philo->time_to_sleep);
	printf("philo [%ld]times: %ld\n", i, philo->n_of_times);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:10 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/02 14:06:37 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo[200];
	long	i;
	long	n_of_philos;

	i = -1;
	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (input_validation(argv[1]) == false)
		return (EXIT_FAILURE);
	n_of_philos = ft_atol(argv[1]);
	if (n_of_philos > 200 || n_of_philos < 1)
		return (EXIT_FAILURE);
	while (++i < n_of_philos)
	{
		if (!init_philo(&philo[i], argv, i) || !philo_validation(&philo[i]))
			return (EXIT_FAILURE);
	}
	thread_creation(philo, n_of_philos);
	return (EXIT_SUCCESS);
}

void	print_philos(t_philo *philo)
{
	printf("philo [%ld] die: %ld\n", philo->philos, philo->time_to_die);
	printf("philo [%ld] eat: %ld\n", philo->philos, philo->time_to_eat);
	printf("philo [%ld] sleep: %ld\n", philo->philos,philo->time_to_sleep);
	printf("philo [%ld] times: %ld\n", philo->philos,philo->n_of_times);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:39 by luizedua          #+#    #+#             */
/*   Updated: 2023/10/30 17:11:36 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philo(t_philo *philo, char **av)
{
	size_t	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (input_validation(av[i]) == false)
			return (false);
		i++;
	}
	philo->philos = ft_atol(av[1]);
	philo->time_to_die = overflow_validation(ft_atol(av[2]));
	philo->time_to_eat = overflow_validation(ft_atol(av[3]));
	philo->time_to_sleep = overflow_validation(ft_atol(av[4]));
	if (av[5] != NULL)
	{
		philo->n_of_times = ft_atol(av[5]);
	}
	else
		philo->n_of_times = LONG_MAX;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:04:30 by luizedua          #+#    #+#             */
/*   Updated: 2023/10/30 17:11:02 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	input_validation(char *input)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(input[i]) == true)
		i++;
	if (input[i] == '\0')
		return (true);
	return (false);
}

time_t	overflow_validation(long nbr)
{
	if (nbr < 0 || nbr * 1000 < nbr)
		return (-1);
	return (nbr * 1000);
}

bool	philo_validation(t_philo *philo)
{
	if (philo->philos > 200 || philo->philos < 1)
		return (false);
	if (philo->n_of_times < 0)
		return (false);
	return (true);
}

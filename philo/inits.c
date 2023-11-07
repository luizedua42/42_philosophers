/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:25:36 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 13:14:03 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

bool	init_philo(t_philo *philo, char **av, long philos)
{
	long			i;
	static int		id;
	static t_rules	rules;

	i = 1;
	while (av[++i] != NULL)
		if (input_validation(av[i]) == false)
			return (false);
	i = -1;
	rules.death = overflow_validation(ft_atol(av[2]));
	rules.famine = overflow_validation(ft_atol(av[3]));
	rules.sleep = overflow_validation(ft_atol(av[4]));
	while (++i < philos)
	{
		philo[i].id = id++;
		philo[i].rules = &rules;
		if (av[5] != NULL)
			philo[i].n_of_meals = overflow_validation(ft_atol(av[5]));
		else
			philo[i].n_of_meals = LONG_MAX;
	}
	
	return(true);
}

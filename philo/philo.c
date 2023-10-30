/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:10 by luizedua          #+#    #+#             */
/*   Updated: 2023/10/30 17:11:15 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = calloc(1, sizeof(t_philo));
	if (argc < 4 || argc > 6)
		return (EXIT_FAILURE);
	init_philo(philo, argv);
	free(philo);
	return (EXIT_SUCCESS);
}

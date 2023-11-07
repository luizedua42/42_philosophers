/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   king_rat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:31:25 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 17:57:53 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	king_rat(t_philo *philos)
{
	if (philos->rules->death + philos->last_meal < ms_clock())
	{
		print_routine(philos, "%ld %d has died\n");
		pthread_mutex_lock(philos->rules->m_death);
		philos->rules->is_alive = false;
		pthread_mutex_unlock(philos->rules->m_death);
		return (true);
	}
	return (false);
}

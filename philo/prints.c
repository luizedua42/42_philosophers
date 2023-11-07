/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:50:32 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 14:16:30 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->rules->print);
	printf(str, ms_clock() - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->rules->print);
}

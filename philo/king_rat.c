/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   king_rat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:31:25 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 14:51:50 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	king_rat(t_philo *philos)
{
	// if (ms_clock() - philos->last_meal >= philos->rules->death)
	if(philos->rules->death + philos->last_meal < ms_clock())
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:12 by luizedua          #+#    #+#             */
/*   Updated: 2023/10/30 17:12:28 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
// Includes
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

//Structs
typedef struct s_philo
{
	long	philos;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	long	n_of_times;
}				t_philo;

//Philo Utils
long			ft_atol(const char *nptr);
bool			ft_isdigit(int c);
bool			init_philo(t_philo *philo, char **av);
bool			input_validation(char *input);
time_t			overflow_validation(long nbr);

#endif

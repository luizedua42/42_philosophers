/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:12 by luizedua          #+#    #+#             */
/*   Updated: 2023/11/07 14:44:30 by luizedua         ###   ########.fr       */
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
# include <sys/time.h>

//Structss
typedef struct s_rules 
{
	time_t	death;
	time_t	famine;
	time_t	sleep;
	pthread_mutex_t *print;
}	t_rules;

typedef struct s_philo
{
	int				id;
	long			n_of_meals;
	time_t			last_meal;
	time_t			start_time;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	t_rules			*rules;
}	t_philo;

//Philo Utils
long				ft_atol(const char *nptr);
bool				ft_isdigit(int c);
bool				init_philo(t_philo *philo, char **av, long philos);
bool				input_validation(char *input);
time_t				overflow_validation(long nbr);
bool				philo_validation(t_philo *philo, long n_of_philos);
time_t				ms_clock(void);
void				print_routine(t_philo *philo, char *str);

// Routine
void				goto_bed(t_philo *philos);
void				go_eat(t_philo *philos);
void				go_think(t_philo *philos);
void				forklift(t_philo *philos);
void				forkdrop(t_philo *philos);
bool				king_rat(t_philo *philos);

#endif

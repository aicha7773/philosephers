/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:23:38 by aatki             #+#    #+#             */
/*   Updated: 2023/06/25 21:22:53 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct t_philo
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	left;
	pthread_mutex_t	right;
	pthread_mutex_t *forks;
}					t_philo;

typedef struct t_all
{
	t_philo			*philo;
}					t_all;

int					ft_atoi(char *str);
void				ft_philo(t_philo *philo);

#endif
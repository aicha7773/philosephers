/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:23:38 by aatki             #+#    #+#             */
/*   Updated: 2023/07/10 03:44:07 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct t_general
{
	int					philo_num;
	unsigned long long	time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	pthread_mutex_t		*forks;
}						t_general;

typedef struct t_philo
{
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	pthread_t			p;
	int					eating_times;
	unsigned long long	last_eat;
}						t_philo;

typedef struct t_all
{
	t_philo				*philo;
	t_general			*general;
	int					i;
	unsigned long long	time;
	pthread_mutex_t		eat;
}						t_all;

int						ft_atoi(char *str);
void					ft_philo(t_general *in);
unsigned long long		get_time(void);
void					ft_sleep(unsigned long long time);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/07/05 00:03:21 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func_mutex(void *arg)
{
	t_all	all;

	all = *(t_all *)arg;
	pthread_mutex_lock(&all.philo[all.i].left);
	pthread_mutex_lock(&all.philo[all.i].right);
	printf ("eating\n");
	usleep(1000000 * all.general->time_to_eat);
	pthread_mutex_unlock(&all.philo[all.i].left);
	pthread_mutex_unlock(&all.philo[all.i].right);
	return (NULL);
}

void	ft_philo(t_general *in)
{
	t_all	all;
	int		i;

	i = 0;
	all.general = in;
	// struct timeval *restrict tp = NULL;
	// void *restrict tzp = NULL;
	all.philo = malloc(sizeof(t_philo) * in->philo_num);
	while (i < in->philo_num)
	{
		all.i = i;
		all.philo[i].left = in->forks[i];
		if (i + 1 == in->philo_num)
			all.philo[i].right = in->forks[0];
		else
			all.philo[i].right = in->forks[i + 1];
		// if (!gettimeofday(tp, tzp))
		// 	return ;
		// int time ;
		// time= (int)tp *1000 + (int)tzp /1000;
		pthread_create(&all.philo[i].p, NULL, &func_mutex, (void *)&all);
		usleep(5);
		i++;
	}
}

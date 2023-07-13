/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/07/13 05:49:18 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*threads_execution(void *arg)
{
	t_all	all;

	all = *(t_all *)arg;
	while (1)
	{
		pthread_mutex_lock(all.philo[all.i].left);
		ft_printf("take right in time : ", all);
		pthread_mutex_lock(all.philo[all.i].right);
		ft_printf("take left in time : ", all);
		ft_printf(" eating in time ", all);
		pthread_mutex_lock(&all.eat);
		all.philo[all.i].last_eat = get_time();
		pthread_mutex_unlock(&all.eat);
		ft_sleep(all.general->time_to_eat);
		pthread_mutex_lock(&all.eating_times);
		all.philo[all.i].eating_times++;
		pthread_mutex_unlock(&all.eating_times);
		pthread_mutex_unlock(all.philo[all.i].left);
		pthread_mutex_unlock(all.philo[all.i].right);
		ft_printf("sleeping in time :", all);
		ft_sleep(all.general->time_to_sleep);
	}
	return (NULL);
}

void	program_starte(t_all all)
{
	int	i;

	i = 0;
	while (i < all.general->philo_num)
	{
		all.i = i;
		all.philo[i].left = &all.general->forks[i];
		if (i + 1 == all.general->philo_num)
			all.philo[i].right = &all.general->forks[0];
		else
			all.philo[i].right = &all.general->forks[i + 1];
		pthread_mutex_lock(&all.philo_mutex);
		pthread_create(&all.philo[i].p, NULL, &threads_execution, (void *)&all);
		pthread_mutex_unlock(&all.philo_mutex);
		usleep(50);
		i++;
	}
}

void	ft_philo(t_general *in)
{
	t_all	all;
	int		i;

	i = 0;
	all.general = in;
	pthread_mutex_init(&all.eat, NULL);
	pthread_mutex_init(&all.eating_times, NULL);
	pthread_mutex_init(&all.print, NULL);
	pthread_mutex_init(&all.philo_mutex, NULL);
	all.philo = malloc(sizeof(t_philo) * in->philo_num);
	all.time = get_time();
	while (i < in->philo_num)
	{
		pthread_mutex_lock(&all.eat);
		all.philo[i].last_eat = all.time;
		pthread_mutex_unlock(&all.eat);
		if (all.general->must_eat > 0)
			all.philo[i].eating_times = 0;
		i++;
	}
	program_starte(all);
	check_death(all);
}

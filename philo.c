/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/07/10 19:23:54 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead(t_all all)
{
	int	i;

	i = 0;
	unsigned long long per;
	while (i < all.general->philo_num)
	{
		pthread_mutex_lock(&all.eat);
		per = get_time() - all.philo[i].last_eat;
		pthread_mutex_unlock(&all.eat);
		if (all.general->time_to_die <= per)
		{
			//printf("philo %d : last mile %llu , time now %llu first time
			// %llu\n",i + 1,all.philo[i].last_eat,get_time(),all.time);
			pthread_mutex_lock(&all.eat);
			printf("philo %d : ------->die time : %llu \n", i + 1, get_time()
					- all.time);
			pthread_mutex_unlock(&all.eat);
			return (0);
		}
		i++;
	}
	i = 0;
	if (all.general->must_eat > 0)
	while (i < all.general->philo_num)
	{
		if (all.philo[i].eating_times <= all.general->must_eat)
			return 1;
		i++;
	}
	if (i == all.general->philo_num)
		return 0;
	return (1);
}

void	*func_mutex(void *arg)
{
	t_all	all;

	all = *(t_all *)arg;
	while (1)
	{
		pthread_mutex_lock(all.philo[all.i].left);
		printf("philo nb :%d take right in time : %llu\n", all.i + 1, get_time()
				- all.time);
		pthread_mutex_lock(all.philo[all.i].right);
		printf("philo nb :%d take left in time : %llu\n", all.i + 1, get_time()
				- all.time);
		printf("philo %d eating %d\n", all.i + 1, all.philo[all.i].eating_times);
		pthread_mutex_lock(&all.eat);
		all.philo[all.i].last_eat = get_time();
		pthread_mutex_unlock(&all.eat);
		ft_sleep(all.general->time_to_eat);
		pthread_mutex_lock(&all.eat);
		all.philo[all.i].eating_times++;
		pthread_mutex_unlock(&all.eat);
		pthread_mutex_unlock(all.philo[all.i].left);
		pthread_mutex_unlock(all.philo[all.i].right);
		printf("philo nb : %d sleeping %llu\n", all.i + 1, get_time()
				- all.time);
		ft_sleep(all.general->time_to_sleep);
	}
	return (NULL);
}

void	ft_philo(t_general *in)
{
	t_all	all;
	int		i;

	i = 0;
	all.general = in;
	pthread_mutex_init(&all.eat, NULL);
	all.philo = malloc(sizeof(t_philo) * in->philo_num);
	all.time = get_time();
	while (i < in->philo_num)
	{
		all.philo[i].last_eat = all.time;
		if (all.general->must_eat > 0)
			all.philo[i].eating_times = 0;
		i++;
	}
	i = 0;
	while (i < in->philo_num)
	{
		all.i = i;
		all.philo[i].left = &in->forks[i];
		if (i + 1 == in->philo_num)
			all.philo[i].right = &in->forks[0];
		else
			all.philo[i].right = &in->forks[i + 1];
		pthread_create(&all.philo[i].p, NULL, &func_mutex, (void *)&all);
		usleep(50);
		i++;
	}
	while (1)
	{
		if (!ft_dead(all))
		{
			free(all.philo);
			return ;
		}
	}
}

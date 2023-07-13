/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/07/13 15:02:21 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*threads_execution(void *arg)
{
	t_philo	*private;

	private = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(private->half[private.i].left);
		ft_printf("take right in time : ", private, 1);
		pthread_mutex_lock(private->half[private.i].right);
		ft_printf("take left in time : ", private, 1);
		ft_printf(" eating in time ", private, 1);
		pthread_mutex_lock(&private->last_eatm);
		private->last_eat = get_time();
		pthread_mutex_unlock(&private->last_eatm);
		ft_sleep(private->gnrl->time_to_eat);
		pthread_mutex_lock(&private->eating_timess);
		private->half[private.i].eating_times++;
		pthread_mutex_unlock(&private->eating_timess);
		pthread_mutex_unlock(private->half[private.i].left);
		pthread_mutex_unlock(private->half[private.i].right);
		ft_printf("sleeping in time :", private, 1);
		ft_sleep(private->gnrl->time_to_sleep);
	}
	return (NULL);
}

void	program_starte(t_philo *private)
{
	int	i;

	i = 0;
	int period;
	while (i < private->gnrl->philo_num)
	{
		private.i = i;
		private->half[i].left = &private->gnrl->forks[i];
		if (i + 1 == private->gnrl->philo_num)
			private->half[i].right = &private->gnrl->forks[0];
		else
			private->half[i].right = &private->gnrl->forks[i + 1];
		// pthread_mutex_lock(&private->philo_mutex);
		pthread_create(&(private[i].p), NULL, &threads_execution, (void *)private);
		// pthread_mutex_unlock(&private->philo_mutex);
		usleep(50);
		i++;
	}
}

void	ft_philo(t_general *in)
{
	t_all	*all;
	int		i;
	t_philo *private;

	i = 0;
	all = malloc(sizeof(t_all));
	all->general = in;
	private = malloc(sizeof(t_philo));
	pthread_mutex_init(&private->last_eatm, NULL);
	pthread_mutex_init(&private->eating_timess, NULL);
	pthread_mutex_init(&private->print, NULL);
	pthread_mutex_init(&all->philo_mutex, NULL);
	private->half=malloc(sizeof(t_half) * in->philo_num);
	//all->philo = malloc(sizeof(t_philo) * in->philo_num);
	all->time = get_time();
	in->time = get_time();
	private->gnrl=in;
	while (i < in->philo_num)
	{
		private->half[i].last_eat = all->time;
		if (all->general->must_eat > 0)
			private->half[i].eating_times = 0;
		i++;
	}
	program_starte(private);
	printf("---------\n");
	all->philo = private;
	//check_death(all);
	free(all);
}

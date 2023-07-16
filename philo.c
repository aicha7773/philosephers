/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/07/16 05:36:21 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*threads_execution(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->left);
		ft_printf("take left fork in time : ", philo, 1);
		pthread_mutex_lock(philo->right);
		ft_printf("take right fork in time : ", philo, 1);
		ft_printf(" eating in time ", philo, 1);
		pthread_mutex_lock(&philo->all->last_eatm);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->all->last_eatm);
		ft_sleep(philo->gnrl->time_to_eat);
		pthread_mutex_lock(&philo->all->eating_timess);
		philo->eating_times++;
		pthread_mutex_unlock(&philo->all->eating_timess);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		ft_printf("sleeping in time :", philo, 1);
		ft_sleep(philo->gnrl->time_to_sleep);
	}
	return (NULL);
}

void	program_starte(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->general->philo_num)
	{
		all->i = i;
		all->philo[i].left = &all->general->forks[i];
		if (i + 1 == all->general->philo_num)
			all->philo[i].right = &all->general->forks[0];
		else
			all->philo[i].right = &all->general->forks[i + 1];
		all->philo[i].all = all;
		all->philo[i].i = i;
		i++;
	}
	i = 0;
	while (i < all->general->philo_num)
	{
		pthread_create(&(all->philo[i].p), NULL, &threads_execution,
			&all->philo[i]);
		usleep(50);
		i++;
	}
}

void	ft_philo(t_general *in)
{
	t_all	*all;
	int		i;
	t_philo	*private;

	i = 0;
	all = malloc(sizeof(t_all));
	all->general = in;
	private = malloc(sizeof(t_philo) * in->philo_num);
	pthread_mutex_init(&all->last_eatm, NULL);
	pthread_mutex_init(&all->eating_timess, NULL);
	pthread_mutex_init(&all->print, NULL);
	all->time = get_time();
	in->time = get_time();
	while (i < in->philo_num)
	{
		private[i].last_eat = all->time;
		private[i].gnrl = in;
		if (all->general->must_eat > 0)
			private[i].eating_times = 0;
		i++;
	}
	all->philo = private;
	program_starte(all);
	check_death(all);
	free(all);
}

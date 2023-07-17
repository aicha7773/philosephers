/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/07/17 08:03:00 by aatki            ###   ########.fr       */
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
		ft_printf("has taken a left fork", philo, 1);
		pthread_mutex_lock(philo->right);
		ft_printf("has taken a right fork", philo, 1);
		ft_printf(" is eating", philo, 1);
		pthread_mutex_lock(&philo->all->last_eatm);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->all->last_eatm);
		ft_sleep(philo->gnrl->time_to_eat);
		pthread_mutex_lock(&philo->all->eating_timess);
		philo->eating_times++;
		pthread_mutex_unlock(&philo->all->eating_timess);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		ft_printf("is sleeping", philo, 1);
		ft_sleep(philo->gnrl->time_to_sleep);
		ft_printf("is thinking", philo, 1);
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
		all->philo[i].last_eat = get_time();
		pthread_create(&(all->philo[i].p), NULL, &threads_execution,
			&all->philo[i]);
		usleep(500);
		i++;
	}
}

t_all	*ft_philo(t_general *in)
{
	t_all	*all;
	int		i;

	i = 0;
	all = malloc(sizeof(t_all));
	all->general = in;
	all->philo = malloc(sizeof(t_philo) * in->philo_num);
	pthread_mutex_init(&all->last_eatm, NULL);
	pthread_mutex_init(&all->eating_timess, NULL);
	pthread_mutex_init(&all->print, NULL);
	all->time = get_time();
	in->time = get_time();
	while (i < in->philo_num)
	{
		all->philo[i].last_eat = all->time;
		all->philo[i].gnrl = in;
		if (all->general->must_eat > 0)
			all->philo[i].eating_times = 0;
		i++;
	}
	program_starte(all);
	check_death(&all);
	return (all);
}

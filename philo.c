/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/06/25 21:31:41 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	func_mutex(t_philo *philo)
{
	philo=0;
}

void	ft_philo(t_philo *in)
{
	t_all	all;
	int		i;

	i = 0;
	all.philo = malloc(sizeof(t_philo) * in->philo_num);
	while (i < in->philo_num)
	{
		all.philo[i].philo_num = in->philo_num;
		all.philo[i].time_to_eat = in->time_to_eat;
		all.philo[i].time_to_sleep = in->time_to_sleep;
		all.philo[i].time_to_die = in->time_to_sleep;
		all.philo[i].must_eat = in->must_eat;
		all.philo[i].left = in->forks[i];
		if (i + 1 == in->philo_num)
			all.philo[i].right = in->forks[0];
		else
			all.philo[i].right = in->forks[i + 1];
		i++;
	}
}

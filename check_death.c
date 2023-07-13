/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:34:12 by aatki             #+#    #+#             */
/*   Updated: 2023/07/13 05:55:54 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	last_meal(t_all all)
{
	int	i;

	i = 0;
	while (i < all.general->philo_num)
	{
		pthread_mutex_lock(&all.eating_times);
		if (all.philo[i].eating_times <= all.general->must_eat)
		{
			pthread_mutex_unlock(&all.eating_times);
			return (1);
		}
		pthread_mutex_unlock(&all.eating_times);
		i++;
	}
	return (0);
}

int	ft_death(t_all all)
{
	int					i;
	unsigned long long	per;

	i = 0;
	while (i < all.general->philo_num)
	{
		pthread_mutex_lock(&all.eat);
		pthread_mutex_lock(&all.philo_mutex);
		per = get_time() - all.philo[i].last_eat;
		pthread_mutex_unlock(&all.eat);
		if (all.general->time_to_die <= per)
		{
			ft_printf("die time :", all);
			pthread_mutex_unlock(&all.philo_mutex);
			return (0);
		}
		pthread_mutex_unlock(&all.philo_mutex);
		i++;
	}
	if (all.general->must_eat > 0)
		return (last_meal(all));
	return (1);
}

void	check_death(t_all all)
{
	// pthread_mutex_lock(&all.philo_mutex);
	while (1)
	{
		if (!ft_death(all))
		{
			free(all.philo);
			break ;
		}
	}
	// pthread_mutex_unlock(&all.philo_mutex);
	pthread_mutex_destroy(&all.eat);
	pthread_mutex_destroy(&all.print);
	pthread_mutex_destroy(&all.eating_times);
	pthread_mutex_destroy(&all.philo_mutex);
}

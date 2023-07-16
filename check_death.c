/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:34:12 by aatki             #+#    #+#             */
/*   Updated: 2023/07/16 05:17:43 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	last_meal(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->general->philo_num)
	{
		pthread_mutex_lock(&all->eating_timess);
		if (all->philo[i].eating_times < all->general->must_eat)
		{
			pthread_mutex_unlock(&all->philo[i].all->eating_timess);
			return (1);
		}
		pthread_mutex_unlock(&all->eating_timess);
		i++;
	}
	ft_printf("die case 2 time :", &all->philo[i - 1], 0);
	return (0);
}

int	ft_death(t_all *all)
{
	int					i;
	unsigned long long	period;

	i = 0;
	while (i < all->general->philo_num)
	{
		pthread_mutex_lock(&all->last_eatm);
		period = get_time() - all->philo[i].last_eat;
		pthread_mutex_unlock(&all->last_eatm);
		if (all->general->time_to_die <= period)
		{
			ft_printf("die time :", &all->philo[i], 0);
			return (0);
		}
		i++;
	}
	if (all->general->must_eat > 0)
		return (last_meal(all));
	return (1);
}

void	check_death(t_all *all)
{
	while (1)
	{
		if (!ft_death(all))
		{
			free(all->philo);
			break ;
		}
		usleep(50);
	}
}

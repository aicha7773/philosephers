/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:43:39 by aatki             #+#    #+#             */
/*   Updated: 2023/07/17 01:07:10 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time(void)
{
	struct timeval	tp;

	if (gettimeofday(&tp, NULL) == -1)
		return (-1);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void	ft_sleep(unsigned long long time)
{
	unsigned long long	t;

	t = get_time();
	while (get_time() - t <= time)
	{
		usleep(100);
	}
}

void	ft_printf(char *s, t_philo *philo, int flag)
{
	pthread_mutex_lock(&philo->all->print);
	printf("%llu philo : %d %s \n", get_time() - philo->all->time, philo->i + 1,
			s);
	if (flag)
		pthread_mutex_unlock(&philo->all->print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:43:39 by aatki             #+#    #+#             */
/*   Updated: 2023/07/13 05:44:46 by aatki            ###   ########.fr       */
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
		usleep(50);
	}
}

void	ft_printf(char *s, t_all all)
{
	pthread_mutex_lock(&all.print);
	printf("philo : %d %s %llu\n", all.i + 1, s, get_time() - all.time);
	pthread_mutex_unlock(&all.print);
}

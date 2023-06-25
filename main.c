/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:08:37 by aatki             #+#    #+#             */
/*   Updated: 2023/06/25 21:29:06 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	int i=0;
	philo = malloc(sizeof(philo));
	if (ac == 6 || ac == 5)
	{
		philo->philo_num = ft_atoi(av[1]);
		philo->time_to_eat = ft_atoi(av[2]);
		philo->time_to_sleep = ft_atoi(av[3]);
		philo->time_to_die = ft_atoi(av[4]);
		if (av[5] && ft_atoi(av[5]))
			philo->must_eat = ft_atoi(av[5]);
		if (!philo->philo_num || !philo->time_to_eat ||
			!philo->time_to_sleep || !philo->time_to_die || !ft_atoi(av[5]))
			return (1);
		philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_num);
		while (i < philo->philo_num)
		{
			pthread_mutex_init(philo->forks[i]);
			i++;
		}
		ft_philo(philo);
	}
}

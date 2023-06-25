/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:08:37 by aatki             #+#    #+#             */
/*   Updated: 2023/06/25 19:10:16 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(philo));
	if (ac == 6 || ac == 5)
	{
		philo->philo_num = ft_atoi(av[1]);
		philo->time_to_eat = ft_atoi(av[2]);
		philo->time_to_sleep = ft_atoi(av[3]);
		philo->time_to_die = ft_atoi(av[4]);
		if (av[5])
			philo->must_eat = ft_atoi(av[5]);
		if (philo->philo_num == 0 || philo->time_to_eat == 0 ||
			philo->time_to_sleep == 0 || philo->time_to_die == 0
				|| philo->must_eat == 0)
			return 1;
		printf("%d %d %d %d %d\n", philo->philo_num, philo->time_to_eat,
				philo->time_to_sleep, philo->time_to_die, philo->must_eat);
	}
}

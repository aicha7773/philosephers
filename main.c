/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:08:37 by aatki             #+#    #+#             */
/*   Updated: 2023/07/13 07:12:35 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spliting_up(int ac, char **av, t_general **general)
{
	int	i;

	i = 0;
	*general = malloc(sizeof(t_general));
	if (ac == 6 || ac == 5)
	{
		(*general)->philo_num = ft_atoi(av[1]);
		(*general)->time_to_die = ft_atoi(av[2]);
		(*general)->time_to_eat = ft_atoi(av[3]);
		(*general)->time_to_sleep = ft_atoi(av[4]);
		if (av[5])
		{
			(*general)->must_eat = ft_atoi(av[5]);
			if (!(*general)->must_eat)
			{
				printf("game over bitchssss hahhahahhahah\n");
				return (0);
			}
		}
		else
			(*general)->must_eat = -1;
		if (!(*general)->philo_num || !(*general)->time_to_eat ||
			!(*general)->time_to_sleep || !(*general)->time_to_die)
			return (0);
		(*general)->forks = malloc(sizeof(pthread_mutex_t)
				* (*general)->philo_num);
		while (i < (*general)->philo_num)
		{
			pthread_mutex_init(&(*general)->forks[i], NULL);
			i++;
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	int			i;
	t_general	*general;

	i = 0;
	general = NULL;
	if (ac == 6 || ac == 5)
	{
		if (spliting_up(ac, av, &general))
		{
			ft_philo(general);
			while (i < general->philo_num)
			{
				pthread_mutex_destroy(&general->forks[i]);
				i++;
			}
			free(general->forks);
			free(general);
		}
	}
}

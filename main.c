/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:08:37 by aatki             #+#    #+#             */
/*   Updated: 2023/07/17 01:18:29 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	for_norm(char **av, t_general **general)
{
	(*general)->philo_num = ft_atoi(av[1]);
	if ((*general)->philo_num < 0)
		return (ft_error());
	(*general)->time_to_die = (unsigned long long)ft_atoi(av[2]);
	(*general)->time_to_eat = ft_atoi(av[3]);
	(*general)->time_to_sleep = ft_atoi(av[4]);
	if (ft_atoi(av[2]) < 0 || (*general)->time_to_eat < 0
		|| (*general)->time_to_sleep < 0)
		return (ft_error());
	if (av[5])
	{
		(*general)->must_eat = ft_atoi(av[5]);
		if (!(*general)->must_eat)
			return (-1);
		if ((*general)->must_eat < 0)
			return (ft_error());
	}
	else
		(*general)->must_eat = -1;
	return (1);
}

int	spliting_up(char **av, t_general **general)
{
	int	i;

	i = 0;
	*general = malloc(sizeof(t_general));
	if (for_norm(av, general) == -1)
		return (0);
	(*general)->forks = malloc(sizeof(pthread_mutex_t) * (*general)->philo_num);
	while (i < (*general)->philo_num)
	{
		pthread_mutex_init(&(*general)->forks[i], NULL);
		i++;
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
		if (spliting_up(av, &general))
		{
			ft_philo(general);
			free(general->forks);
			free(general);
		}
	}
	else
		printf("ERROR\n");
}

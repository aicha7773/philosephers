/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:08:37 by aatki             #+#    #+#             */
/*   Updated: 2023/07/04 23:55:55 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_general	*general;
	int			i;

	i = 0;
	general = malloc(sizeof(general));
	if (ac == 6 || ac == 5)
	{
		general->philo_num = ft_atoi(av[1]);
		general->time_to_eat = ft_atoi(av[2]);
		general->time_to_sleep = ft_atoi(av[3]);
		general->time_to_die = ft_atoi(av[4]);
		if (av[5] && ft_atoi(av[5]))
			general->must_eat = ft_atoi(av[5]);
		if (!general->philo_num || !general->time_to_eat ||
			!general->time_to_sleep || !general->time_to_die || !ft_atoi(av[5]))
			return (1);
		general->forks = malloc(sizeof(pthread_mutex_t) * general->philo_num);
		while (i < general->philo_num)
		{
			pthread_mutex_init(&general->forks[i], NULL);
			i++;
		}
		ft_philo(general);
	}
}

// int main()
// {
// 	int o=255+255+55;
// 	char c=(char)o;
// 	printf("%c\n",c);
// 	char *a;
// 	a=&c;
// 	a+=1;
// 	printf("%c\n",*a);
// 	a++;
// 	printf("%c\n",*a);
// }

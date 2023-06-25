/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:50 by aatki             #+#    #+#             */
/*   Updated: 2023/06/25 18:52:49 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int ac, char **av)
// {
// 	int	n_philosophers;
// 	int	t_die;
// 	int	t_eat;
// 	int	t_sleep;
// 	int	t_must_eat;
// 	int	i;
// 	int	k;
// 	int	np_can_it;

// 	i = 1;
// 	k = 1;
// 	if (ac == 6)
// 	{
// 		n_philosophers = ft_atoi(av[1]);
// 		t_die = ft_atoi(av[2]);
// 		t_eat = ft_atoi(av[3]);
// 		t_sleep = ft_atoi(av[4]);
// 		t_must_eat = ft_atoi(av[5]);
// 		np_can_it = n_philosophers / 2;
//         n_philosophers++;
// 		int te=t_eat;
// 		int ts=t_sleep;
// 		//int tt=t_t
// 		while (k <= 2)
// 		{
// 			i = k;
// 			while (i < n_philosophers)
// 			{
// 				printf("%d %d has taken a fork\n", i,te);
// 				te+=t_eat;
// 				i += 2;  
// 			}
// 			i = k;
// 			while (i < n_philosophers)
// 			{
// 				printf("timestamp_in_ms %d is eating\n", i);
// 				i += 2;
// 			}
// 			i = k;
// 			while (i < n_philosophers)
// 			{
// 				printf("%d %d is sleeping\n", i,ts);
// 				ts+=t_sleep;
// 				i += 2;
// 			}
// 			i = k;
// 			while (i < n_philosophers)
// 			{
// 				printf("timestamp_in_ms %d is thinking\n", i);
// 				i += 2;
// 			}
// 			i = k;
// 			while (i < n_philosophers)
// 			{
// 				printf("timestamp_in_ms %d died\n", i);
// 				i += 2;
// 			}
// 			k++;
// 		}
// 	}
// }



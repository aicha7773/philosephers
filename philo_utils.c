/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:13:15 by aatki             #+#    #+#             */
/*   Updated: 2023/06/25 19:07:53 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_max(unsigned long long a, int sign)
{
	if (a >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (a > 9223372036854775807 && sign == -1)
		return (1);
	return ((int)a * sign);
}

// int	ft_atoi(const char *str)
// {
// 	int					i;
// 	int					s;
// 	unsigned long long	a;

// 	i = 0;
// 	s = 1;
// 	a = 0;
// 	while (str[i] == '\t' || str[i] == '\n' \
// 			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' \
// 			|| str[i] == ' ')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			s *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		a = a * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (ft_max(a, s));
// }

int ft_error()
{
	printf("ERROOR\n");
	return 0;
}

void	for_normm(char *s, int *i, int *si)
{
	if (s[*i] == '-')
		*si *= -1;
	else
		*si = 1;
	(*i)++;
}

int	ft_atoi(char *str)
{
	int					i;
	int					si;
	unsigned long long	a;

	i = 0;
	si = 1;
	a = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		for_normm(str, &i, &si);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (ft_error());
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			a = a * 10 + str[i] - '0';
		i++;
	}
	if ((!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0') || a > 2147483647)
		return (ft_error());
	return (a * si);
}

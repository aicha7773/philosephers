/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:13:15 by aatki             #+#    #+#             */
/*   Updated: 2023/07/17 01:18:22 by aatki            ###   ########.fr       */
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

int	ft_error(void)
{
	printf("ERROR\n");
	return (-1);
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
	if (!str)
		return (-1);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		for_normm(str, &i, &si);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			a = a * 10 + str[i] - '0';
		i++;
	}
	if ((!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0') || a > 2147483647)
		return (-1);
	return (a * si);
}

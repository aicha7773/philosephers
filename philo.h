/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:23:38 by aatki             #+#    #+#             */
/*   Updated: 2023/06/25 18:41:14 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int	ft_atoi(char *str);

typedef struct t_philo
{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
}t_philo;

#endif
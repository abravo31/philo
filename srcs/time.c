/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandabravo <amandabravo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:12:37 by abravo            #+#    #+#             */
/*   Updated: 2023/01/22 17:43:33 by amandabravo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	ft_usleep(long long time)
{
	long long	start;

	start = get_time_now();
	while((get_time_now() - start) < time)
		usleep(150);
	return (1);
}
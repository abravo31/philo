/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:12:37 by abravo            #+#    #+#             */
/*   Updated: 2023/01/21 18:47:44 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (get_time_now() - time);
	return (0);
}

void	exec_action(long long time)
{
	usleep(time * 1000);
}

/*int	ft_usleep(long long time)
{
	long int	start_time;

	start_time = get_time_now();
	while ((get_time_now() - start_time) < time)
		usleep(150);
	return (1);
}*/
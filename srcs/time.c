/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:12:37 by abravo            #+#    #+#             */
/*   Updated: 2023/01/24 21:35:20 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*long long	ft_usleep(t_philo *p, long long time)
{
	struct timeval    start;
    struct timeval    end;

    gettimeofday(&start, NULL);
    end = start;
    end.tv_sec += (time / 1000);
    end.tv_usec += (time % 1000) * 1000;

    while(1)
    {
        if(check_death(p))
            return(1);
        gettimeofday(&start, NULL);
        if(start.tv_sec > end.tv_sec || (start.tv_sec == end.tv_sec && start.tv_usec >= end.tv_usec))
            break;
        usleep(1000);
    }
	return (0);
}*/

long long ft_usleep(t_philo *p, long long time)
{
 
	long long	time_end;

	time_end = get_time_now() + time;
	while (get_time_now() <= time_end)
	{
		if(check_death(p))
            return(1);
		usleep(100);
	}
	return (0);
}
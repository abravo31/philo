/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:31 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/25 19:04:05 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	j = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		j = i;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[j] == '-')
		n = -n;
	return (n);
}

int	error_msg(char *s)// t_data *params)// t_philo *p, int malloc)
{
	/*if (malloc)
	{
		if (par->death)
			free(par->death);
		if (par->fork)
			free(par->fork);
		if (p)
			free(p);
	}*/		
	return (printf("%s", s));
}

void	print_routine(t_philo *p, char *color, char *action)
{
	pthread_mutex_lock(&p->params->mutex_p);
	// printf("hello\n");
	if (p->params->over)
	{
		pthread_mutex_unlock(&p->params->mutex_p);
		return ;
	}
	// printf("%lld %d\n", p->thread_start, p->index);
	printf("%s%lld %d %s\n", color, get_time_now() - p->thread_start, p->index, action);
	//printf("thread_start: %lld, time\n", p->thread_start);
	// printf("time: %lld\n", get_time_now() - p->thread_start);
	// printf("index %d\n", p->index);
	// printf("action: %s\n", action);
	pthread_mutex_unlock(&p->params->mutex_p);
}

void	final_print(int alive)
{
	printf("						\n");
	if (alive)
		printf("	(☞ﾟヮﾟ)☞ no one died today	\n");
	else
		printf("	¯\\_(ツ)_/¯			\n");
	printf("						\n");
}
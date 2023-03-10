/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:18:15 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/26 23:01:58 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_meals(t_philo *p)
{
	pthread_mutex_lock(&p->params->mutex_p);
	if (p->times_ate == p->times_must_eat)
	{
		p->params->nb_finished = p->params->nb_finished + 1;
		if (p->params->nb_finished == p->params->nb_phi)
		{
			p->params->over = 1;
			printf("\e[0m  All philosophers have eaten %d times\n",
				p->times_must_eat);
			pthread_mutex_unlock(&p->params->mutex_p);
			return ;
		}
	}
	pthread_mutex_unlock(&p->params->mutex_p);
}

int	check_death(t_philo *p)
{
	long int	now;

	pthread_mutex_lock(&p->params->mutex_p);
	if (p->params->over)
	{
		pthread_mutex_unlock(&p->params->mutex_p);
		return (1);
	}
	now = get_time_now() - p->eating;
	if (now >= p->time_to_die)
	{
		p->params->over = 1;
		printf("%s%lld %d %s\n", RESET, get_time_now() - p->thread_start,
			p->index, DIED);
		pthread_mutex_unlock(&p->params->mutex_p);
		return (1);
	}
	pthread_mutex_unlock(&p->params->mutex_p);
	return (0);
}

int	ft_sleeping_and_thinking(t_philo *p)
{
	if (check_death(p))
		return (1);
	print_routine(p, BLUE, SLEEP);
	ft_usleep(p, p->time_to_sleep);
	if (check_death(p))
		return (1);
	print_routine(p, G_BLUE, THINK);
	return (0);
}

int	ft_eating(t_philo *p)
{
	if (take_forks(p))
		return (1);
	p->eating = get_time_now();
	if (check_death(p))
		return (1);
	print_routine(p, PINK, EAT);
	ft_usleep(p, p->time_to_eat);
	p->times_ate++;
	pthread_mutex_lock(&p->l_f->mutex_f);
	p->l_f->free = 0;
	pthread_mutex_unlock(&p->l_f->mutex_f);
	pthread_mutex_lock(&p->r_f->mutex_f);
	p->r_f->free = 0;
	pthread_mutex_unlock(&p->r_f->mutex_f);
	if (p->check_meals)
		check_meals(p);
	return (0);
}

void	*philo_routine(void *doing)
{
	t_philo	*p;

	p = (t_philo *)doing;
	pthread_mutex_lock(&p->params->mutex_p);
	p->thread_start = p->params->start;
	p->eating = p->params->start;
	pthread_mutex_unlock(&p->params->mutex_p);
	if (p->index % 2 != 0)
		// usleep(10000);
		ft_usleep(p, p->time_to_eat * 0.9 + 1);
	while (p->index <= p->params->nb_phi)
	{
		if (ft_eating(p))
			return (NULL);
		if (ft_sleeping_and_thinking(p))
			return (NULL);
	}
	return (NULL);
}

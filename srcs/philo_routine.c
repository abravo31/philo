/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:18:15 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/23 21:17:56 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_died(t_philo *p)
{
	print_routine(p, RESET, DIED);
	pthread_mutex_lock(&p->params->mutex_p);
	p->params->over = 1;
	pthread_mutex_unlock(&p->params->mutex_p);
	//p->dead = 1;
	// pthread_mutex_unlock(&p->l_f->mutex_f);
	// pthread_mutex_unlock(&p->r_f->mutex_f);
	return (1);
}

int	check_death(t_philo *p)
{
	long int	now;

	pthread_mutex_lock(&p->params->mutex_p);
	if (p->params->over)
	{
		pthread_mutex_unlock(&p->params->mutex_p);
		return(1);
	}
	now = get_time_now() - p->eating;
	if (now >= p->params->time_to_die)
	{
		pthread_mutex_unlock(&p->params->mutex_p);
		someone_died(p);
		return (1);
	}
	pthread_mutex_unlock(&p->params->mutex_p);
	return (0);
}

int	ft_sleeping_and_thinking(t_philo *p)
{
	if(check_death(p))
		return(1);
	print_routine(p, BLUE, SLEEP);
	ft_usleep(p, p->params->time_to_sleep);
	if(check_death(p))
		return(1);
	print_routine(p, G_BLUE, THINK);
	return (0);
}

int	take_fork(t_philo *p)
{
	pthread_mutex_lock(&p->l_f->mutex_f);
	if(p->l_f->free == 0)
	{
		p->l_f->free = 1;
		pthread_mutex_unlock(&p->l_f->mutex_f);
		return (1);
		
	}
	pthread_mutex_unlock(&p->l_f->mutex_f);
	if (check_death(p))
		return (1);
	pthread_mutex_lock(&p->r_f->mutex_f);
	if (p->r_f->free == 0)
	{
		p->r_f->free = 1;
		pthread_mutex_unlock(&p->r_f->mutex_f);
		return (1);
	}
	pthread_mutex_unlock(&p->r_f->mutex_f);
	return (0);
}

int	take_forks(t_philo *p)
{
	int	i;
	
	i = 0;
	while(i < 2)
	{
		if (take_fork(p))
		{
			i++;
			if(check_death(p))
				return (1);
			print_routine(p, PINK, FORK);
		}
	}
	return (0);
}

int ft_eating(t_philo *p)
{
	take_forks(p);
	p->eating = get_time_now();
	if(check_death(p))
		return(1);
	print_routine(p, GREEN, EAT);
	ft_usleep(p, p->params->time_to_eat);
	p->times_ate++;
	pthread_mutex_lock(&p->l_f->mutex_f);
	p->l_f->free = 0;
	pthread_mutex_unlock(&p->l_f->mutex_f);
	pthread_mutex_lock(&p->r_f->mutex_f);
	p->r_f->free = 0;
	pthread_mutex_unlock(&p->r_f->mutex_f);
	return(0);
}

void    *philo_routine(void *doing)
{
    t_philo *p;

    p = (t_philo *)doing;
	// if (p->index & 1)
	// 	ft_usleep(p, p->params->time_to_eat * 0.9 + 1);
	if(p->index % 2 != 0)
		usleep(10000);
		//ft_usleep(p, p->params->time_to_eat / 10);
    while(p->index < p->params->nb_phi)
	{
		if(ft_eating(p))
			return NULL;
		if(ft_sleeping_and_thinking(p))
			return NULL;
	}
    return NULL;
}

//p_thread_mutex_destroy(&mutex)
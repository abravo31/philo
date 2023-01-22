/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandabravo <amandabravo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:18:15 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/22 17:42:54 by amandabravo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//pthread_mutex_t mutex;

//p_thread_mutex_init(&mutex, NULL)

void ft_eating(t_philo *p)
{
    pthread_mutex_lock(&p->l_f->mutex_f);
	print_routine(p, FORK);
	pthread_mutex_lock(&p->r_f->mutex_f);
	print_routine(p, FORK);
	p->eating = get_time_now();
	ft_usleep(p->params->time_to_eat);
	print_routine(p, EAT);
	//p->iter_num++;
	pthread_mutex_unlock(&p->l_f->mutex_f);
	pthread_mutex_unlock(&p->r_f->mutex_f);
}

void    *philo_routine(void *doing)
{
    t_philo *p;

    p = (t_philo *)doing;
    ft_eating(p);

    return NULL;
}

//p_thread_mutex_destroy(&mutex)
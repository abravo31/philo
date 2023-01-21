/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:18:15 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/21 20:20:20 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//pthread_mutex_t mutex;

//p_thread_mutex_init(&mutex, NULL)

void philo_eating(t_philo *p, t_data *params)
{
    int i;
    
    i = 0;
    while(i < params->nb_philo)
    {
        p->l_f[i] 
    }
    
}

void    *philo_routine()
{
    while(philo_eating)
    {
        p_thread_mutex_lock(&mutex);
        eat++;
        p_thread_mutex_unlock(&mutex);
    }
}

//p_thread_mutex_destroy(&mutex)
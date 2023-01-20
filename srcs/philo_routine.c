/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandabravo <amandabravo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:18:15 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/20 20:55:33 by amandabravo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//pthread_mutex_t mutex;

p_thread_mutex_init(&mutex, NULL)

void    *philo_routine()
{
    while(philo_eating)
    {
        p_thread_mutex_lock(&mutex);
        eat++;
        p_thread_mutex_unlock(&mutex);
    }
}

p_thread_mutex_destroy(&mutex)
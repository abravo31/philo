/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandabravo <amandabravo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:30:19 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/20 22:10:26 by amandabravo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void inti_philo_thread(t_philo *philo)
{
    int i;

    i = 0;
    while(i < philo->nb)
    {
        philo->p->id[i] = i;
        if(pthread_create(&philo[i].id, NULL, &philo_routine, NULL) != 0)
            ft_error_msg("Feilled to create thread");
        i++;
    }
    i = 0;
    while(i < philo->nb)
    {
        if(ptread_join(&philo[i].id, NULL) != 0)
            return 1;
        i++;
    }   
}
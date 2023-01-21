/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:30:19 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/21 20:14:41 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo_thread(t_data *params, t_philo *p)
{
    int i;

    i = 0;
    while(i < params->nb_phi)
    {
        p[i].r_f = p[(i + 1) % params->nb_phi].l_f;
        if(pthread_create(&p[i].id, NULL, &philo_routine, &p[i]) != 0)
            error_msg("Feilled to create thread", params);
        i++;
    }
    i = 0;
    params->start = get_time_now();
    while(i < params->nb)
    {
        p[i].eating = params->start;
        if(ptread_join(&p[i].id, NULL) != 0)
            return 1;
        i++;
    }   
}

int	philosophers(t_data *params)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * params->nb_philo);
	if (!philo || init_philo(params, philo))
		return (EXIT_FAILURE);
	if (init_philo_thread(params, philo))
		return (EXIT_FAILURE);
	//check_thread(params, philo);
	//end_thread(params, philo);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:30:19 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/26 22:55:45 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(t_philo *p, char *color, char *action)
{
	pthread_mutex_lock(&p->params->mutex_p);
	if (p->params->over)
	{
		pthread_mutex_unlock(&p->params->mutex_p);
		return ;
	}
	printf("%s%lld %d %s\n", color, get_time_now() - p->thread_start,
		p->index, action);
	pthread_mutex_unlock(&p->params->mutex_p);
}

static int	init_philo_thread(t_data *params, t_philo *p)
{
	int	i;

	i = 0;
	params->start = get_time_now();
	while (i < params->nb_phi)
	{
		p[i].r_f = p[(i + 1) % params->nb_phi].l_f;
		if (pthread_create(&p[i].id, NULL, &philo_routine, &p[i]) != 0)
			return (error_msg("Failed to create thread", params, p, 1));
		i++;
	}
	i = 0;
	while (i < params->nb_phi)
	{
		if (pthread_join(p[i].id, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	philosophers(t_data *params, char **av)
{
	t_philo	*p;

	p = malloc(sizeof(t_philo) * params->nb_phi);
	if (!p || init_philo(params, p, av) != 0)
	{
		free(p);
		free(params->f);
		return (EXIT_FAILURE);
	}
	if (init_philo_thread(params, p))
		return (EXIT_FAILURE);
	pthread_mutex_destroy(&params->mutex_p);
	pthread_mutex_destroy(&params->f->mutex_f);
	free(p);
	free(params->f);
	return (0);
}

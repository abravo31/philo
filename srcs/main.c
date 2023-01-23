/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:17:56 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/23 19:22:48 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *params, t_philo *p)
{
	int i;

    i = 0;
    while (i < params->nb_phi)
	{
		p[i].index = i;
		p[i].times_ate = 0;
		p[i].died = 0;
		p[i].l_f = &params->f[i];
		p[i].r_f = 0;
		p[i].params = params;
		p[i].thread_start = 0;
		p[i].eating = 0;
		i++;
	}
	return (0);
}

void  init_fork(t_data *params)
{
    int i;

	i = 0;
	params->f = (t_fork *)malloc(sizeof(t_fork) * params->nb_phi);
    while (i < params->nb_phi)
    {
		// printf("%d\n", i);
		// f[i] = malloc(sizeof(t_fork));
		params->f[i].free = 0;
		if((pthread_mutex_init(&params->f[i].mutex_f, NULL)) == -1)
			error_msg("Error\nMutex_fork init failed\n");
        i++;
    }
	return ;
}

/*static int	init_params_mutex(t_params *p)
{
	int	i;

	i = -1;
	//p->death = 0;
	//p->death = malloc(sizeof(pthread_mutex_t));
	//if (!p->death)
		//return (error_msg("Error\nMutex death: malloc failed\n", p, 0, 1));
	//p->fork = malloc(sizeof(pthread_mutex_t) * p->num);
	//if (!p->fork)
		//return (error_msg("Error\nMutex fork: malloc failed\n", p, 0, 1));
	//if (pthread_mutex_init(p->death, NULL) == -1)
		//return (error_msg("Error\nMutex init failed\n", p, 0, 1));
	//while (++i < p->num)
	//	if (pthread_mutex_init(&p->fork[i], NULL) == -1)
			//return (error_msg("Error\nMutex_fork init failed\n", p);// 0, 1));
	//return (0);
}*/

int	init_params(t_data *params, char **av)
{
	params->nb_phi = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
	//printf("num philo: %d\n", params->nb_phi);
	init_fork(params);
	//philo->max_iter = -2;
	//philo->check_meal = 0;
	params->start = 0;
	//philo->ready = 0;
	if (av[5])
	{
		//p->check_meal = 1;
		params->times_have_eat = ft_atoi(av[5]);
	}
	params->over = 0;
	if (params->nb_phi > 0)
	{
		if((pthread_mutex_init(&params->mutex_p, NULL)) == -1)
			return (error_msg("Error\nMutex_philo init failed\n")); //, 0, 1));
	}			
	return (params->nb_phi <= 0 || params->time_to_die <= 0 || params->time_to_eat <= 0 || params->time_to_sleep <= 0);
}

int main (int ac, char **av)
{
    t_data params;
    
    if ((ac != 5 && ac != 6) || init_params(&params, av))
		printf("Error: invalid arguments\n");
    	//return (error_msg("Error: invalid arguments\n", &params)); //0, 1));
	if (philosophers(&params))
		return (EXIT_FAILURE);
	return (0);
}
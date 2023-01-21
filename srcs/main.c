/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:17:56 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/21 20:09:25 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *params, t_philo *p)
{
	int i;

    i = 0;
    while (i <= params->nb_phi)
	{
		p[i].times_ate = 0;
		p[i].status = -1;
		p[i].l_f = &params->f[i];
		p[i].r_f = 0; 
		i++;
	}
}

static void  init_fork(t_data *params)
{
    int i;

    i = 0;
    while (i <= params->nb_phi)
    {
        params->f[i] = i;
		params->f[i]->free = 0;
		if((pthread_mutex_init(&f[i].mutex_f, NULL)) == -1);
			return (error_msg("Error\nMutex_fork init failed\n", params));
        i++;
    }
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

static int	init_params(t_data *params, char **av)
{
	//int	mutex;

	//mutex = -1;
	params->nb_phi = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
	params->f = init_fork(params);
	//philo->max_iter = -2;
	//philo->check_meal = 0;
	params->start = 0;
	//philo->ready = 0;
	if (ag[5])
	{
		//p->check_meal = 1;
		params->times_eat = ft_atoi(ag[5]);
	}
	//p->over = 0;
	if (params->nb_philo > 0)
	{
		if((params->mutex_p = pthread_mutex_init(params->mutex_p, NULL)) == -1);
			return (error_msg("Error\nMutex_philo init failed\n", params); //, 0, 1));
	}			
	//return (mutex || p->num <= 0 || p->t2d <= 0 || p->t2e <= 0
		//|| p->t2s <= 0 || p->max_iter == 0);*/
}

int main (int ac, char **av)
{
    t_data params;
    
    if ((ac != 5 && ac != 6) || init_params(&params, av))
    	return (ft_error_msg("Error: invalid arguments\n", &params, 0, 1));
	//if (philosophers(&params))
		//return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
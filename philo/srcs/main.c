/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:17:56 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/26 22:55:30 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	init_philo(t_data *params, t_philo *p, char **av)
{
	int	i;

	i = -1;
	while (++i < params->nb_phi)
	{
		p[i].index = i + 1;
		p[i].times_ate = 0;
		p[i].died = 0;
		p[i].l_f = &params->f[i];
		p[i].r_f = 0;
		p[i].params = params;
		p[i].thread_start = 0;
		p[i].eating = 0;
		p[i].time_to_die = ft_atoi(av[2]);
		p[i].time_to_eat = ft_atoi(av[3]);
		p[i].time_to_sleep = ft_atoi(av[4]);
		p[i].check_meals = 0;
		if (av[5])
		{
			p[i].check_meals = 1;
			p[i].times_must_eat = ft_atoi(av[5]);
		}
	}
	return (0);
}

void	init_fork(t_data *params)
{
	int	i;

	i = 0;
	params->f = (t_fork *)malloc(sizeof(t_fork) * params->nb_phi);
	if (!params->f)
	{
		pthread_mutex_destroy(&params->mutex_p);
		free(params->f);
		return ;
	}
	while (i < params->nb_phi)
	{
		params->f[i].free = 0;
		if ((pthread_mutex_init(&params->f[i].mutex_f, NULL)) == -1)
			error_msg("Error\nMutex_fork init failed\n", params, NULL, 1);
		i++;
	}
	return ;
}

int	init_params(t_data *params, char **av)
{
	params->nb_phi = ft_atoi(av[1]);
	init_fork(params);
	params->start = 0;
	params->over = 0;
	params->nb_finished = 0;
	if (params->nb_phi > 0)
	{
		if ((pthread_mutex_init(&params->mutex_p, NULL)) == -1)
			return (error_msg("Error\nMutex_philo init failed\n",
					params, NULL, 0));
	}			
	return (params->nb_phi <= 0);
}

int	main(int ac, char **av)
{
	t_data	params;

	if (!check_args(ac, av) || init_params(&params, av))
	{
		printf("Error: invalid arguments\n");
		return (0);
	}
	if (philosophers(&params, av))
	{
		return (EXIT_FAILURE);
	}
	return (0);
}

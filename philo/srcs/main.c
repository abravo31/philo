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
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_philo(t_data *params, t_philo *p, char **av)
{
	int		i;

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
}

int	init_fork(t_data *params)
{
	int		i;

	i = 0;
	while (i < params->nb_phi)
	{
		params->f[i].free = 0;
		if ((pthread_mutex_init(&params->f[i].mutex_f, NULL)) == -1)
			return (printf("Error: Mutex_fork init failed\n"), 1);
		i++;
	}
	return (0);
}

int	init_params(t_data *params, t_philo *p, t_fork *f, char **av)
{
	params->nb_phi = ft_atoi(av[1]);
	params->f = f;
	if (init_fork(params))
		return (-1);
	params->start = 0;
	params->over = 0;
	params->nb_finished = 0;
	if (params->nb_phi > 0)
	{
		if ((pthread_mutex_init(&params->mutex_p, NULL)) == -1)
			return (printf("Error: Mutex_philo init failed\n"), 1);
	}			
	init_philo(params, p, av);
	return (params->nb_phi <= 0);
}

int	main(int ac, char **av)
{
	t_data	params;
	t_philo	*p;
	t_fork	*f;

	if (check_args(ac, av))
		return (printf("Error: invalid arguments\n"), 1);
	p = malloc(sizeof (t_philo) * ft_atoi(av[1]));
	if (!p)
		return (printf("Error: philo malloc failed"), 1);
	f = malloc(sizeof (t_fork) * ft_atoi(av[1]));
	if (!f)
		return (printf("Error: fork malloc failed"), free(p), 1);
	if (init_params(&params, p, f, av) || philosophers(&params, p, av))
		return (free(p), free(f), 1);
	return (free(p), free(f), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandabravo <amandabravo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:17:56 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/20 20:32:08 by amandabravo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  init_mutex(t_data *philo)
{
    int i;

    i = 0;
    while (i <= philo->nb)
    {
        philo->fork[i] = i;
        i++;
    }
}

static int	init_params(t_data *philo, char **av)
{
	int	mutex;

	mutex = -1;
	philo->nb = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	/*philo->max_iter = -2;
	philo->check_meal = 0;
	philo->start = 0;
	philo->ready = 0;
	if (ag[5])
	{
		p->check_meal = 1;
		p->max_iter = ft_atoi(ag[5]);
	}
	p->over = 0;*/
	if (philo->nb > 0)
		mutex = init_mutex(philo);
	//return (mutex || p->num <= 0 || p->t2d <= 0 || p->t2e <= 0
		//|| p->t2s <= 0 || p->max_iter == 0);
}

int main (int ac, char **av)
{
    t_data philo;
    
    if ((ac != 5 && ac != 6) || init_params(&philo, av))
    	return (ft_error_msg("Error: invalid arguments\n", &philo, 0, 1));
	//if (philosophers(&philo))
		//return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
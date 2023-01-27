/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:31 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/26 22:59:13 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	j = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		j = i;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[j] == '-')
		n = -n;
	return (n);
}

int	take_left(t_philo *p)
{
	int	left_taken;

	left_taken = 0;
	while (left_taken == 0)
	{
		pthread_mutex_lock(&p->l_f->mutex_f);
		if (p->l_f->free == 0)
		{
			p->l_f->free = 1;
			left_taken = 1;
			print_routine(p, G_CYAN, FORK);
		}
		if (check_death(p))
		{
			pthread_mutex_unlock(&p->l_f->mutex_f);
			return (2);
		}
		pthread_mutex_unlock(&p->l_f->mutex_f);
		usleep(1);
	}
	return (1);
}

int	take_right(t_philo *p)
{
	int	right_taken;

	right_taken = 0;
	while (right_taken == 0)
	{
		pthread_mutex_lock(&p->r_f->mutex_f);
		if (p->r_f->free == 0)
		{
			p->r_f->free = 1;
			right_taken = 1;
			print_routine(p, G_CYAN, FORK);
		}
		if (check_death(p))
		{
			pthread_mutex_unlock(&p->r_f->mutex_f);
			return (2);
		}
		pthread_mutex_unlock(&p->r_f->mutex_f);
		usleep(1);
	}
	return (1);
}

int	take_forks(t_philo *p)
{
	int	left_taken;
	int	right_taken;

	left_taken = 0;
	right_taken = 0;
	while (left_taken == 0 || right_taken == 0)
	{
		left_taken = take_left(p);
		if (left_taken == 2)
			return (1);
		// usleep(10);
		right_taken = take_right(p);
		if (right_taken == 2)
			return (1);
	}
	return (0);
}

// int	error_msg(char *s, t_fork *f)
// {
// 	if (f)
// 		free(f);
// 	return (printf("%s", s));
// }

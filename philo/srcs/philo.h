/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:18:14 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/26 21:52:33 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

/* Colors */

# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

/* Routines messages */

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

typedef struct s_fork
{
	int				free;
	pthread_mutex_t	mutex_f;
}	t_fork;

typedef struct s_data
{
	int				nb_phi;
	int				over;
	long long		start;
	int				nb_finished;
	t_fork			*f;
	pthread_mutex_t	mutex_p;
}	t_data;

typedef struct s_philo
{
	pthread_t	id;
	int			index;
	int			times_ate;
	int			died;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_must_eat;
	int			check_meals;
	long long	eating;
	long long	thread_start;
	t_fork		*r_f;
	t_fork		*l_f;
	t_data		*params;
}	t_philo;

/** Philos **/

void		init_philo(t_data *params, t_philo *p, char **av);
int			philosophers(t_data *params, t_philo *p, char **av);
void		*philo_routine(void *doing);
int			check_death(t_philo *p);
void		check_meals(t_philo *p);

/** Tools **/

int			ft_atoi(const char *nptr);
void		print_routine(t_philo *p, char *color, char *action);
void		final_print(int alive);
int			take_forks(t_philo *p);

/** Time **/

long long	get_time_now(void);
long long	ft_usleep(t_philo *p, long long time);

#endif

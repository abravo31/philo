/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandabravo <amandabravo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:18:14 by amandabravo       #+#    #+#             */
/*   Updated: 2023/01/20 22:04:44 by amandabravo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_fork
{
    int             free;
    pthread_mutex_t f_mutex;       
}   t_fork

typedef struct s_philo
{
    pthread_t id;
    int status;
}   t_philo

typedef struct s_data
{
    int             nb;
    int             time_die;
    int             time_eat;
    int             time_sleep;
    t_philo         *p;
    t_fork          **f;
    pthread_mutex_t d_mutex;  
}   t_data

# endif
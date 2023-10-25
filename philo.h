/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:00:43 by manumart          #+#    #+#             */
/*   Updated: 2023/10/23 15:24:44 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_fork
{
    int *taken;
    pthread_mutex_t *mutex;
}   t_fork;

typedef struct s_philodata
{
    int Nphil;
    
    int timetoeat;
    int timetosleep;
    int timesmusteat;
    int eatamount;
    unsigned long timetodie;
    unsigned long timestart;
    
    int *id;
    int *checkdeath;
    pthread_mutex_t *msg;
    pthread_mutex_t *death;
    t_fork *left_fork;
    t_fork *right_fork;
}   t_philo;

typedef struct s_philofork
{
    int *id;
    
    t_fork left_fork;
    t_fork right_fork;
}   t_philofork;


int ft_atoi(char *str);
int checkargs(int argc,char **argv,t_philo *data);
int ft_putstr_toerr(char *str);
int ft_exit_error(char *msg);

#endif
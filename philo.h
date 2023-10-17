/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:00:43 by manumart          #+#    #+#             */
/*   Updated: 2023/10/17 17:08:23 by manumart         ###   ########.fr       */
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
    pthread_mutex_t locked;
}   t_fork;

typedef struct s_philodata
{
    int Nphil;
    
    int timetoeat;
    int timetosleep;
    int timesmusteat;   
    unsigned long timetodie;
    unsigned long timestart;
}   t_philodata;

typedef struct s_philo
{
    int *id;
    
    t_fork left_fork;
    t_fork right_fork;
}   t_philo;


int ft_atoi(char *str);
int checkargs(int argc,char **argv,t_philodata *data);
int ft_putstr(char *str);

#endif
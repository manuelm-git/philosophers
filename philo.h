/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:00:43 by manumart          #+#    #+#             */
/*   Updated: 2023/10/25 20:32:17 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
typedef struct s_fork
{
    int istaken;
    pthread_mutex_t mutex;
}   t_fork;

typedef struct s_death
{
    int status;
    pthread_mutex_t mutex;
}       t_death;

typedef struct s_philodata
{
    int Nphil;
    int timetoeat; 
    int timetosleep;
    int timesmusteat;
    int eatamount;
    unsigned long timetodie;
    unsigned long start;
    pthread_mutex_t msg;
    t_death death;
}       t_philodata;

typedef struct s_philo
{
    int id;
    int mealseaten;
    unsigned long lasttimeeaten;
    pthread_t philo;
    t_philodata *philodata;
    t_fork *forks;
}       t_philo;





t_philodata *philodata(void);
int ft_atoi(char *str);
int checkargs(int argc,char **argv);
int ft_putstr_toerr(char *str);
int ft_exit_error(char *msg);
t_fork *initforks(t_philodata *philodata);
unsigned int get_time(void);
void init_philos(t_philo *philo);
int clean_everything(t_philo *philos,t_fork *forks);
#endif
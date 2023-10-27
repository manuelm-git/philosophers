#include "philo.h"

t_fork *initforks(t_philodata *philodata)
{
    int i;

    i = 0;
    philo()->forks = malloc(sizeof(t_fork) * philodata->Nphil);
    if(!philo()->forks)
        ft_exit_error("Error: failed to allocate forks");
    while (i < philodata->Nphil)
    {
        philo()->forks->istaken = 0;
        if(pthread_mutex_init(&philo()[i].forks->mutex,NULL))
            ft_exit_error("Error: failed to allocate forks");
        i++;
    }
    return (0);
}

int init_threads(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->philodata->Nphil)
    {
        if(pthread_create(&philo->philo,NULL,&routine,))
        i++;
    }
    i = 0;
    while (i < philo->philodata->Nphil)
    {
        if(pthread_join())
        i++;
    }
    
}

void init_philos(t_philo *philo,t_philodata *philodata)
{
    int i;

    i = 0;
    while(i < philodata->Nphil)
    {
        philo[i].philodata = philodata;
        philo[i].id = i + 1;
        philo[i].mealseaten = 0;
        philo[i].lasttimeeaten = get_time();
        i++;
    }
}

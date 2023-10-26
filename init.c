#include "philo.h"

t_fork *initforks(t_philodata *philodata)
{
    int i;
    t_fork *forks;

    i = 0;
    forks = malloc(sizeof(t_fork) * philodata->Nphil);
    if(!forks)
        ft_exit_error("Error: failed to allocate forks");
    while (i < philodata->Nphil)
    {
        forks[i].istaken = 0;
        if(pthread_mutex_init(&forks[i].mutex,NULL))
            ft_exit_error("Error: failed to allocate forks");
        i++;
    }
    return (0);
}

//int initmutex(t_philo **philodata)


void init_philos(t_philo *philo,t_philodata *philodata,t_fork *forks)
{
    int i;

    i = 0;
    while(i < philodata->Nphil)
    {
        philo[i].forks = forks;
        philo[i].philodata = philodata;
        philo[i].id = i + 1;
        philo[i].mealseaten = 0;
        philo[i].lasttimeeaten = get_time();
        i++;
    }
}

#include "philo.h"
int initforks(t_fork **fork,int nforks)
{
    int i;
    pthread_mutex_t *mutex;
   
    i = 0;
    fork = malloc(sizeof(int) * nforks);
    if(!fork)
        ft_exit_error("Fork error");
    mutex = malloc(sizeof(pthread_mutex_t) * nforks);
    if(!mutex)
        ft_exit_error("Mutex error");
    while (i < nforks)
    {
        fork[i]->taken = 0;
        pthread_mutex_init(&fork[i]->mutex,NULL);
        i++;
    }
    return (0);
}

//int initmutex(t_philo **philodata)


int init_philo(t_philo **philo, t_philofork **forks)
{
    int i;

    i = 0;

    philo = malloc(sizeof(t_philo) * (*philo)->Nphil);
    while (i < (*philo)->Nphil)
    {
        philo[i]->checkdeath = 0;
        philo[i]->id = i;
        philo[i]->eatamount = 0;
        philo[i]->right_fork = forks[i];
        if(i == 0)
            philo[i]->left_fork = forks[(*philo)->Nphil - 1];
        else
            philo[i]->left_fork = forks[i - 1];
        i++;
    }
    return (0); 
}
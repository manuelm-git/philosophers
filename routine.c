#include "philo.h"

void routine(void *currentphilo)
{
    int i;

    i = (int)currentphilo;
    philo()->lasttimeeaten = get_time();
    if(philo()->philodata->Nphil % 2 != 0 && philo()->id == philodata()->Nphil)
    {
        
    }
}
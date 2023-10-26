/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:04 by manumart          #+#    #+#             */
/*   Updated: 2023/10/26 18:12:55 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



t_philodata *philodata(void)
{
    static t_philodata data;

    return(&data);
}
int checkargs(int argc,char **argv)
{
    if (argc != 5 && argc != 6)
        ft_exit_error("Invalid number of arguments");
    else if(argc >= 5 && argc <= 6)
    {
        philodata()->Nphil = ft_atoi(argv[1]);
        philodata()->timetodie = ft_atoi(argv[2]);
        philodata()->timetoeat = ft_atoi(argv[3]);
        philodata()->timetosleep = ft_atoi(argv[4]);
        if (argv[5])
            philodata()->timesmusteat = ft_atoi(argv[5]);
        else
            philodata()->timesmusteat = -1;
    }
    return (0);
}
void	all_prints(t_philo *philo)
{
	printf(" [num philo] %d philos\n", philo->philodata->Nphil);
	printf(" [time to die] %ld ms\n", philo->philodata->timetodie);
	printf(" [time to eat] %d ms\n", philo->philodata->timesmusteat);
	printf(" [time to sleep] %d ms\n", philo->philodata->timetoeat);
	printf(" [num times to eat] %d meals\n\n", philo->philodata->timetosleep);

}
int main(int argc,char **argv)
{
    t_philo *philos;
    t_fork  *forks;
    
    if(checkargs(argc,argv))
        return(0);
    forks = initforks(philodata());
    if(!forks)
        clean_everything(NULL,forks);
    philos = malloc(sizeof(t_philo) * philodata()->Nphil);
    if(!philos)
        clean_everything(philos,forks);
    init_philos(philos,philodata(),forks);
    
}

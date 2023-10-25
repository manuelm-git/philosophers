/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:04 by manumart          #+#    #+#             */
/*   Updated: 2023/10/25 20:14:02 by manumart         ###   ########.fr       */
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
    init_philos(philos);
    
}
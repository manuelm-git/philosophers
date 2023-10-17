/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:04 by manumart          #+#    #+#             */
/*   Updated: 2023/10/17 17:58:27 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int checkargs(int argc,char **argv,t_philodata *philo)
{
    if (argc != 5 && argc != 6)
        exit(ft_putstr("Error : Invalid number of arguments\n"));
    else if(argc >= 5 && argc <= 6)
    {
        philo->Nphil = ft_atoi(argv[1]);
        philo->timetodie = ft_atoi(argv[2]);
        philo->timetoeat = ft_atoi(argv[3]);
        philo->timetosleep = ft_atoi(argv[4]);
        if (argv[5])
            philo->timesmusteat = ft_atoi(argv[5]);
        else
            philo->timesmusteat = -1;
    }
    return (0);
}
int main(int argc,char **argv)
{
    t_philodata data;

    if(checkargs(argc,argv,&data))
        return(0);
    else
    {
       
    }

}
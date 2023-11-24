/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:04 by manumart          #+#    #+#             */
/*   Updated: 2023/11/24 16:43:57 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_philo *philo(void)
{
    static t_philo philo;

    return(&philo);
}
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

//remove
void	all_prints()
{
    if(philodata()->Nphil)
	    printf(" [num philo] %d philos\n", philodata()->Nphil);
	if(philodata()->timetodie)
    printf(" [time to die] %ld ms\n", philodata()->timetodie);
	if(philodata()->timesmusteat)
        printf(" [time to eat] %d ms\n", philodata()->timesmusteat);
	if(philodata()->timetodie)
        printf(" [time to sleep] %d ms\n", philodata()->timetoeat);
	if(philodata()->timetosleep)
        printf(" [num times to eat] %d meals\n\n", philodata()->timetosleep);

}
int main(int argc,char **argv)
{
    if(checkargs(argc,argv))
        return(0);
    
    //    clean_everything(philos);
    init_philos(philo(),philodata());
    all_prints(philos);
}


//passa com limites?
//passa com ++ ou -- com input?
//e mais umas merdas
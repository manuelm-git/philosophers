/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:04 by manumart          #+#    #+#             */
/*   Updated: 2023/10/11 19:35:33 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int checkargs(int argc,char **argv,t_philodata *data)
{
    if (argc != 5 && argc != 6)
        return (write(1,"error",5));
    else if(argc >= 5 && argc <= 6)
    {
        (*data).Nphil = ft_atoi(argv[1]);
        (*data).timetodie = ft_atoi(argv[2]);
        (*data).timetoeat = ft_atoi(argv[3]);
        (*data).timetosleep = ft_atoi(argv[4]);
        if (argv[5])
            (*data).timesmusteat = ft_atoi(argv[5]);
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
        printf("%d\n",data.Nphil);
        printf("%ld\n",data.timetodie);
        printf("%d\n",data.timetoeat);
        printf("%d\n",data.timetosleep);
        if (argv[5])
            printf("%d\n",data.timesmusteat);
    }

}
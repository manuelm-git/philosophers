/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeNclean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:42 by manumart          #+#    #+#             */
/*   Updated: 2023/10/25 20:34:13 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int get_time(void)
{
    struct timeval tv;
    
    if(gettimeofday(&tv,NULL))
        return(0);
    return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	clean_everything(t_philo *philos, t_fork *forks)
{
	int	i;

	i = 0;
	if (forks)
	{
		while (i < philodata()->Nphil)
			pthread_mutex_destroy(&forks[i++].mutex);
		free(forks);
	}
	i = 0;
	if (philos)
	{
		pthread_mutex_destroy(&philodata()->msg);
		pthread_mutex_destroy(&philodata()->death.mutex);
		free(philos);
	}
	return (0);
}
#include <stdio.h>
#include <limits.h>
#include "philo.h"

int ft_putstr_toerr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        write(2,&str[i],1);
        i++;
    }
    return(0);
}
int ft_atoi(char *str)
{
    int i = 0;
    int pn = 1;
    int num = 0;
    while((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            pn = -1;
        i++;
    }
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + str[i] - '0';
            i++;
        }
        else
        return(ft_exit_error("Invalid input"));
    }
    if (num > 0 && num < INT_MAX)
        return (num * pn);
    else
        return (ft_exit_error("Invalid input"));
}

int ft_exit_error(char *msg)
{
   ft_putstr_toerr("Error:");
   ft_putstr_toerr(msg);
   ft_putstr_toerr("\n");
    return(0);
}
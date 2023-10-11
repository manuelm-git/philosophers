#include <stdio.h>
#include <limits.h>
#include "philo.h"

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
    while(str[i] >= '0' && str[i] <= '9')
    {   
        num = num * 10 + str[i] - '0';
        i++;
    }
    if (num > 0 && num < INT_MAX)
        return (num * pn);
    else
        exit(write(1,"error\n",6));
}

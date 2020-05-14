#include "ft_minishell.h"

void    ft_store(char *s)
{
    int i;

    i = 0;
    while (store[i] != 0){
        if (store[i] != 0)
            i++;
        else{
            store[i] = ft_strdup(s);
            return ;
        }
    }
}
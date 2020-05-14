#include "ft_minishell.h"

void    ft_delstore(char *s)
{
    int i;

    i = 0;
    while (store[i] != 0){
        if (ft_strcmp(s,store[i]) == 0)
            free(store[i]);
    }
}
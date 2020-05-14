#include "ft_minishell.h"

size_t    ft_chectstore(char *s)
{
    int i;

    i = 0;
    while (store[i] != 0){
        if (ft_strcmp(store[i],s) == 0)
            return 1;
    }
    return 0;
}
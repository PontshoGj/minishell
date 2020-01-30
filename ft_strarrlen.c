#include "ft_minishell.h"

int ft_strarrlen(char **arr){
    int i;

    i = 0;
    while(arr[i] != 0)
        i++;
    return i;
}
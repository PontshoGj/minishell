#include "ft_minishell.h"

void ft_envir(void){
    int i = 0;
    while (environ[i] != 0)
        ft_putendl(environ[i++]);
}

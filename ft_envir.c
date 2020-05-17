#include "ft_minishell.h"

void    ft_envir(void){
    int i;

    i = 0;
    if (ft_envKeys()){
        while (environ[i] != 0)
            ft_putendl(environ[i++]);
    }else{
        ft_putendl("minishell: no such file or directory: env");
    }
}
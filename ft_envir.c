#include "ft_minishell.h"

void ft_envir(void){
    int i;
    char *env;

    i = 0;
    env = ft_envKey("PATH=");
    if (env != 0){
        while (environ[i] != 0){
            ft_putendl(environ[i++]);
        }
    }else{
        ft_putendl("minishell: no such file or directory: env");
    }
    free(env);
}

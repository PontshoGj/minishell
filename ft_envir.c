#include "ft_minishell.h"

void ft_envir(void){
    int i;
    char *env;
    // ft_putnbr(ft_strarrlen(environ));
    // ft_putstr("\n");
    i = 0;
    env = ft_envKey("PATH=");
    if (env != 0){
        while (environ[i] != 0){
            ft_putnbr(i);
            ft_putendl(environ[i++]);
        }
    }else{
        ft_putendl("minishell: no such file or directory: env");
 }
    free(env);
}

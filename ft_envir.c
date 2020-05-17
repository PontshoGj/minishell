#include "ft_minishell.h"

void ft_envir(void){
    int i;
   char *env;
   

   i = 0;
   env = 0;
   env = ft_envKey("PATH=");
    //ft_putendl(env);
    if (env != 0){
        free(env);
        while (environment[i] != 0){
           ft_putendl(environment[i++]);
    }
   }else{
       ft_putendl("minishell: no such file or directory: env");
   }
}
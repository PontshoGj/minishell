#include "ft_minishell.h"

void ft_cd(char *s, char **env)
{
    char *var[2];

    if (ft_strcmp("home", s) == 0 || ft_strcmp("~", s) == 0){
        chdir(ft_strsub(env[23], 5, ft_strlen(env[23])));
        var[0] = "HOME";
        var[1] = ft_strsub(env[23], 5, ft_strlen(env[23]));
        execve("/bin/setenv", var, NULL);
    }else{
        chdir(s);
    }
}
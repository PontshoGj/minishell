#include "ft_minishell.h"

void ft_cd(char *s)
{
    char *var[2];

    if (ft_strcmp("home", s) == 0 || ft_strcmp("~", s) == 0){
        chdir(ft_strsub(environ[23], 5, ft_strlen(environ[23])));
        var[0] = "HOME";
        var[1] = ft_strsub(environ[23], 5, ft_strlen(environ[23]));
        execve("/bin/setenv", var, environ);
    }else{
        chdir(s);
    }
}

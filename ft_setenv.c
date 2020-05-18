#include "ft_minishell.h"

void        realloc_environ(char *s){
    int     i;
    char    **new_environ;

    i = 0;
    new_environ = (char **)malloc(sizeof(char *) * (ft_strarrlen(environ) + 3));
    while(environ[i] != 0){
        new_environ[i] = ft_strdup(environ[i]);
        i++;
    }
    if (ft_envKeys(s))
        ft_unsetenv(s);
    new_environ[i] = ft_strdup(s);
    i++;
    new_environ[i] = 0;
    if (store != 0){
        ft_freearry(store);
    }
    store = new_environ;
    environ = new_environ;
}

void    ft_setenv(char *new_var){
    if (ft_strstr(new_var, "=") != 0 && ft_strlen(new_var) > 1)
        realloc_environ(new_var);
}
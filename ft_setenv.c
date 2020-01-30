#include "ft_minishell.h"

int ft_strarrlen(char **arr){
    int i;

    i = 0;
    while(arr[i] != 0)
        i++;
    return i;
}

char **realloc_environ(char *s){
    int i;
    char **new_environ;

    i = 0;
    new_environ = (char **)malloc(sizeof(char *) * (ft_strarrlen(environ) + 1));
    new_environ[ft_strarrlen(environ) + 1] = 0;
    while(environ[i] != 0){
        new_environ[i] = environ[i];
        i++;
    }
    new_environ[i] = s;
    return new_environ;
}

void    ft_setenv(char *new_var){
    if (new_var != 0)
        environ = realloc_environ(new_var);
}
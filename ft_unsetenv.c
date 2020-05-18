#include "ft_minishell.h"

void        realloc_environ_one(char *s){
    int     i;
    int     j;
    char    **new_environ;
    char    *temp;

    i = 0;
    j = 0;
    temp = 0;
    new_environ = (char **)malloc(sizeof(char *) * (ft_strarrlen(environ)) + 1);
    while(environ[j] != 0){
        temp = ft_strsub(environ[j], 0, ft_strlenc(environ[j], '='));
        if (ft_strcmp(s, temp))
            new_environ[i++] = ft_strdup(environ[j]);
        j++;
        free(temp);
    }
    new_environ[i] = 0;
    if (store != 0)
        ft_freearry(store);
    store = new_environ;
    environ = new_environ;
}

void ft_unsetenv(char *var){
    char *temp;
    char  *temp2;

    temp = ft_strjoin(var, "=");
    temp2 = ft_envKey(temp);
   if (ft_envKeys() && temp2 != 0)
        realloc_environ_one(var);
    free(temp);
    free(temp2);
}
#include "ft_minishell.h"

char **realloc_environ_one(char *s){
    int i;
    int j;
    char **new_environ;

    i = 0;
    j = 0;
    new_environ = (char **)malloc(sizeof(char *) * (ft_strarrlen(environ)) + 1);
    // new_environ[ft_strarrlen(environ)] = 0;
    while(environ[j] != 0){
        if (ft_strcmp(s, ft_strsub(environ[j], 0, ft_strlenc(environ[j], '='))))
            new_environ[i++] = environ[j];
        j++;
    }
    new_environ[i] = 0;
    return new_environ;
}

void ft_unsetenv(char *var){
    
   char *envKey;
   envKey = ft_strdup(var);
   envKey = ft_strjoin(envKey, "=");
   if (ft_envKey(envKey) != 0)
        environ = realloc_environ_one(var);
}
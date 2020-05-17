#include "ft_minishell.h"

char **realloc_environment(char *s){
    int i;
    char **new_environment;

    i = 0;
    new_environment = (char **)malloc(sizeof(char *) * (ft_strarrlen(environment) + 2));
    while(environment[i] != 0){
        new_environment[i] = ft_strdup(environment[i]);
        i++;
    }
    new_environment[i] = s;
    new_environment[i + 1] = NULL;
    ft_freearry(environment);
    return new_environment;
}

void    ft_setenv(char *new_var){
    if (new_var != 0)
        if (ft_strstr(new_var, "=") != 0 && ft_strlen(new_var) > 1)
            environment = realloc_environment(new_var);

}
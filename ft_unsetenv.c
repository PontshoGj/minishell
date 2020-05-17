#include "ft_minishell.h"

char **realloc_environment_one(char *s){
    int i;
    int j;
    char **new_environment;
    char *sub;

    i = 0;
    j = 0;
    new_environment = (char **)malloc(sizeof(char *) * (ft_strarrlen(environment)) + 2);
   // new_environment[ft_strarrlen(environment) - 1] = 0;
    while(environment[j] != 0){
        sub = ft_strsub(environment[j], 0, ft_strlenc(environment[j], '='));
        if (ft_strcmp(s, sub))
            new_environment[i++] = environment[j];
        j++;
        free(sub);
    }
    new_environment[i] = 0;
    return new_environment;
}

void ft_unsetenv(char *var){
    
   char *envKey;
   char *tmp;
   char *env;

   tmp = ft_strdup(var);
   envKey = ft_strjoin(tmp, "=");
   free(tmp);
   env = ft_envKey(envKey);
   free(envKey);
   if (env != 0)
        environment = realloc_environment_one(var);
    free(env);
}
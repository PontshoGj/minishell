#include "ft_minishell.h"

char        *ft_envKey(char *dirs)
{
    char    *envkey;
    int     i;

    i = 0;
    envkey = 0;
    while(environ[i] != 0){
        if (ft_strstr(environ[i], dirs)){
            envkey = ft_strsub(environ[i], ft_strlen(dirs), ft_strlen(environ[i]));
        }
        i++;
    }
    return envkey;
}

size_t      ft_envKeys()
{
    char    *temp;
    int     i;

    i = 0;
    temp = 0;
    while(environ[i] != 0){
        temp = ft_strsub(environ[i], 0, ft_strlenc(environ[i], '='));
        if (ft_strcmp(temp, "PATH") == 0){
            free(temp);
            return 1;
        }
        free(temp);
        i++;
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

extern char **environ;

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

char **realloc_environ_one(char *s){
    int i;
    int j;
    char **new_environ;

    i = 0;
    j = 0;
    new_environ = (char **)malloc(sizeof(char *) * (ft_strarrlen(environ) -1));
    new_environ[ft_strarrlen(environ) -1] = 0;
    while(environ[j] != 0){
        if (ft_strcmp(s, ft_strsub(environ[j], 0, ft_strlenc(environ[j], '='))))
            new_environ[i++] = environ[j];
        environ[j];
    }
    // environ = new_environ;
    return new_environ;
}

int main(int ac, char **av)
{
    int i = 0;
    char **s;

    // environ = realloc_environ("FOO=bar");
    // while(environ[i] != 0)
    //     printf("%s\n", environ[i++]);
    // i = 0;
    // printf("\n\n\n");
    // environ = realloc_environ_one("COLORTERM");
    // while(environ[i] != 0)
    //     printf("%s\n", environ[i++]);
    if (ft_strstr(av[1], "=") != 0 && ft_strlen(av[1]) > 1)
        printf("A");
    
    // execve(av[1], av, NULL);

    // setenv("FOO", "bar", NULL);

    // while(environ[i] != 0){
    //     if (ft_strcmp("HOME", ft_strsub(environ[i], 0, ft_strlenc(environ[i], '='))) == 0)
    //         return i;
    // //         printf("%s = %d\n", ft_strsub(environ[i], 0, ft_strlenc(environ[i], '=')), i);
    //     i++;
    // }
    return 0;
}
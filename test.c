#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

// extern char **environment;

// int ft_strarrlen(char **arr){
//     int i;

//     i = 0;
//     while(arr[i] != 0)
//         i++;
//     return i;
// }

// char **realloc_environment(char *s){
//     int i;
//     char **new_environment;

//     i = 0;
//     new_environment = (char **)malloc(sizeof(char *) * (ft_strarrlen(environment) + 1));
//     new_environment[ft_strarrlen(environment) + 1] = 0;
//     while(environment[i] != 0){
//         new_environment[i] = environment[i];
//         i++;
//     }
//     new_environment[i] = s;
//     return new_environment;
// }

// char **realloc_environment_one(char *s){
//     int i;
//     int j;
//     char **new_environment;

//     i = 0;
//     j = 0;
//     new_environment = (char **)malloc(sizeof(char *) * (ft_strarrlen(environment) -1));
//     new_environment[ft_strarrlen(environment) -1] = 0;
//     while(environment[j] != 0){
//         if (ft_strcmp(s, ft_strsub(environment[j], 0, ft_strlenc(environment[j], '='))))
//             new_environment[i++] = environment[j];
//         environment[j];
//     }
//     // environment = new_environment;
//     return new_environment;
// }

// int main(int ac, char **av)
// {
//     int i = 0;
//     char **s;

//     // environment = realloc_environment("FOO=bar");
//     // while(environment[i] != 0)
//     //     printf("%s\n", environment[i++]);
//     // i = 0;
//     // printf("\n\n\n");
//     // environment = realloc_environment_one("COLORTERM");
//     // while(environment[i] != 0)
//     //     printf("%s\n", environment[i++]);
//     if (ft_strstr(av[1], "=") != 0 && ft_strlen(av[1]) > 1)
//         printf("A");
    
//     // execve(av[1], av, NULL);

//     // setenv("FOO", "bar", NULL);

//     // while(environment[i] != 0){
//     //     if (ft_strcmp("HOME", ft_strsub(environment[i], 0, ft_strlenc(environment[i], '='))) == 0)
//     //         return i;
//     // //         printf("%s = %d\n", ft_strsub(environment[i], 0, ft_strlenc(environment[i], '=')), i);
//     //     i++;
//     // }
//     return 0;
// }

// int main(int ac, char **av){
//     printf("%s", av[1]);
//     execve(av[1], NULL, NULL);
//     return 0;
// }

extern char **environment;

void exc(char **av)
{
    if (ft_strstr(av[0], "/bin/") != 0 && av){
        av[0] = ft_strdup("/usr/bin/env");
        execve(av[0], av, environment);
    }else
    {
        if (fork() == 0){
        av[0] = ft_strjoin("/bin/", av[0]);
        execve(av[0], av, (char **)0);
        }
    }
    
}

int main(int ac, char **av) 
{ 
        //A null terminated array of character  
        //pointers 
        // char *args[]={"/bin/ls","la", (char *)0};
        av++; 
        // execve(av[0], av, (char **)0); 
        exc(av);      
        /*All statements are ignored after execvp() call as this whole  
        process(execDemo.c) is replaced by another process (EXEC.c) 
        */
        printf("Ending-----"); 
      
    return 0; 
} 
#include "ft_minishell.h"
#include <sys/wait.h>

void ft_execute_comand(char **av)
{
    if (fork() == 0){
        if ((ft_strstr(av[0], "/bin/") != 0 || ft_strstr(av[0], "/") != 0) && av){
            execve(av[0], av, environ) < 1 ? ft_putendl(ft_strjoin("minishell: no such file or directory: ", av[0])) : (void)0;
        }else{
            av[0] = ft_strjoin("/bin/", av[0]);
            execve(av[0], av, environ) < 1 ? ft_putendl(ft_strjoin("minishell: command not found: ", av[0])) : (void)0; 
        }
        exit(0);
    }
    wait(0);
}
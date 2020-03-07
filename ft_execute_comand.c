#include "ft_minishell.h"

void ft_execute_comand(char **av)
{
    if (fork() == 0){
        if ((ft_strstr(av[0], "/bin/") != 0 || ft_strstr(av[0], "/") != 0) && av){
            execve(av[0], av, environ) ? ft_putendl(ft_strcat("minishell: no such file or directory: ", av[0])) : (void)0;
        }else{
            av[0] = ft_strjoin("/bin/", av[0]);
            execve(av[0], av, environ) ? ft_putendl(ft_strcat("minishell: command not found: ", av[0])) : (void)0; 
        }
    }
    wait(0);
}
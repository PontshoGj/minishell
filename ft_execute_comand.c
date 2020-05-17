#include "ft_minishell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


void ft_execute_comand(char **av)
{
    char    *temp;

    temp = 0;                                                  
    if (fork() == 0){
            if ((ft_strstr(av[0], "/bin/") != 0 || ft_strstr(av[0], "/") != 0) && av){
                temp = ft_strjoin("minishell: no such file or directory: ", av[0]);
                execve(av[0], av, environ) < 1 ? ft_putendl(temp) : (void)0;
            }else if(ft_envKeys("PATH=")){
                temp = ft_strjoin("minishell: command not found: ", av[0]);                                                     
                av[0] = ft_strjoin("/bin/", av[0]);                             
                execve(av[0], av, environ) < 1 ? ft_putendl(temp) : (void)0;
            }else{
                temp =ft_strjoin("minishell: no such file or directory: ", av[0]);                                                          
                ft_putendl(temp);
            }
        free(temp);
        exit(0);                                                                
    }                                                                           
    wait(0);  
}
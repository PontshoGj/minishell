#include "ft_minishell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *which(char *cmd, char *path)
{
    int i;
    char **paths;
    char *fullpath;
    struct stat file_info;
    char *tmp;
    if (path == NULL)
        return NULL;
    if (lstat(cmd, &file_info) == 0)
        return (ft_strdup(cmd));
    i = 0;
    paths = ft_strsplit(path, ':');
   
    while(paths[i] != NULL){
        tmp = ft_strjoin(paths[i], "/");
        fullpath = ft_strjoin(tmp, cmd);
        free(tmp);
        if (lstat(fullpath, &file_info) == 0)
            break ;
        ft_strdel(&fullpath);
        i++;
    }
    ft_freearry(paths);
    return fullpath;
}

void ft_execute_comand(char **av)
{
    char *envk;
    char *fullpath;
    envk = 0;
    
    if (fork() == 0){
        envk = ft_envKey("PATH=");
        fullpath = which(av[0], envk);
        ft_strdel(&envk);
        if  (fullpath != NULL)
            execve(fullpath, av, environment);
        else
        {
            ft_putstr("minishell: command not found: ");
            ft_putendl(av[0]);
        }
        free(fullpath);
        free(environment);
        ft_freearry(av);

        exit(0);
    }
    wait(0);
}
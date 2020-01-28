#include "ft_minishell.h"

void ft_envir(char **opt){
    execve("/bin/bash", opt, NULL);
}
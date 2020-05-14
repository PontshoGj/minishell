#include "ft_minishell.h"

char *ft_pwd()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    return (ft_strdup(cwd));
}
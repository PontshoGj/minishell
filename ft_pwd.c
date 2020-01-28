#include "ft_minishell.h"

char *ft_pwd()
{
    char cwd[1024];
    char *cwds = (char *)malloc(sizeof(char) * 1024);
    getcwd(cwd, sizeof(cwd));
    cwds = strcpy(cwds,cwd);
    return (cwds);
}
#include "ft_minishell.h"

static void ft_print_echo(char *param)
{
    int i;

    i = 0;
    while (param[i] != '\0')
    {
        if(param[i] != '"')
            ft_putchar(param[i]);
        i++;
    }
    ft_putchar('\n');
}

static int  find_home()
{
    int i;

    i = 0;
    while(environment[i] != 0){
        if (ft_strcmp("HOME", ft_strsub(environment[i], 0, ft_strlenc(environment[i], '='))) == 0)
            return i;
        i++;
    }
    return (0);
}
void     ft_echo(char *input)
{
    char *param;

    param = ft_strsub(input, ft_strlenc(input, ' ') + 1, ft_strlen(input));
    if (ft_strcmp(param, "~") == 0)
        ft_putendl(ft_strsub(environment[find_home()], 5, ft_strlen(environment[find_home()])));
    else if (param[0] == '$')
    {
        ft_putendl(ft_envKey(ft_strcat(ft_strsub(param, 1, ft_strlen(param)), "=")));       
    }
    else
        ft_print_echo(param);
    free(param);
}
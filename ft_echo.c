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
    while(environ[i] != 0){
        if (ft_strcmp("HOME", ft_strsub(environ[i], 0, ft_strlenc(environ[i], '='))) == 0)
            return i;
        i++;
    }
    return (0);
}
void     ft_echo(char *input)
{
    char *param;
    char *temp;

    temp = 0;
    param = ft_strsub(input, ft_strlenc(input, ' ') + 1, ft_strlen(input));
    if (ft_strcmp(param, "~") == 0){
        temp = ft_strsub(environ[find_home()], 5, ft_strlen(environ[find_home()]));
        ft_putendl(temp);
        free(temp);
    }
    else if (param[0] == '$')
    {
        temp = ft_strsub(param, 1, ft_strlen(param));
        free(param);
        param = ft_envKey(ft_strcat(temp, "="));
        ft_putendl(param);       
        free(temp);
    }
    else
        ft_print_echo(param);
    free(param);
}
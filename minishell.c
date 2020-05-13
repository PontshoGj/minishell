#include "ft_minishell.h"

char        *ft_tebTospace(char *s)
{
    int i;
    
    i = 0;
    while(s[i]){
        if (s[i] == '\t')
            s[i] = ' ';
        i++;
    }
	return s;
}
void ft_options(char *input){
    char **hold;
    int i;
    char *command;

    i = 0;
    command = ft_strtrim(ft_tebTospace(input));
    if (ft_strcmp(command,"") == 0)
        return;
    hold = ft_strsplit(command, ' ');
    (ft_strcmp("cd" , hold[0]) == 0 && i == 0) ? ft_cd(hold[1]) : i++;
    (ft_strcmp("echo", hold[0]) == 0 && i == 1) ? ft_echo(command): i++;
    (ft_strcmp("setenv", hold[0]) == 0 && i == 2) ? ft_setenv(hold[1]): i++;
    (strcmp("unsetenv", hold[0]) == 0 && i == 3) ? ft_unsetenv(hold[1]): i++;
    (ft_strlen(command) > 0 && i == 4) ? ft_execute_comand(hold) : i++;
    i = 0;
}

void ft_nooptions(char *input){
    char    **av;
    int     i;
    char *pwds = ft_pwd();
    char *command;

    i = 0;
    command = ft_strtrim(input);
    if (ft_strcmp(command,"") == 0)
        return;
    av = (char **)malloc(sizeof(char *) * 2);
    av[0] = command;
    av[1] = (char *)0;
    (ft_strcmp("pwd", command) == 0 && i == 0) ? ft_putendl(pwds): i++;
    (ft_strcmp("env", command) == 0 && i == 1) ? ft_envir(): i++;
    
   // (ft_strcmp("exit", command) == 0 && i == 2) ? exit(1): i++;
    (ft_strcmp("cd", command) == 0 && i == 2) ? ft_cd("home"): i++;
    (ft_strlen(command) > 0 && i == 3) ? ft_execute_comand(av) : i++;
    i = 0;
    free(av);
    free(pwds);
    if (ft_strcmp("exit", command) == 0)
    {
        free(av);
        free(pwds);   
        free(command);
        exit(1);
    }
    free(command);
    
}

void ft_process(void){
    char *input;
    
    while(1){
        ft_putstr("&> ");
        get_next_line(0, &input);
        (ft_elementcount(input, ' ') > 1) ? ft_options(input) : ft_nooptions(input);
        free(input);
    }
}

int main(void) {
    ft_process();
    return 0;
}

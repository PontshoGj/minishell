#include "ft_minishell.h"

void ft_options(char *input){
    char **hold;
    int i;

    i = 0;
    hold = ft_strsplit(input, ' ');
    (ft_strcmp("cd" , hold[0]) == 0 && i == 0) ? ft_cd(hold[1]) : i++;
    (ft_strcmp("echo", hold[0]) == 0 && i == 1) ? ft_echo(input): i++;
    (ft_strcmp("setenv", hold[0]) == 0 && i == 2) ? ft_setenv(hold[1]): i++;
    (strcmp("unsetenv", hold[0]) == 0 && i == 3) ? ft_unsetenv(hold[1]): i++;
    (ft_strlen(input) > 0 && i == 4) ? ft_execute_comand(hold) : i++;
    i = 0;
}

void ft_nooptions(char *input){
    char    **av;
    int     i;

    i = 0;
    av = (char **)malloc(sizeof(char *) * 2);
    av[0] = input;
    av[1] = (char *)0;
    (ft_strcmp("pwd", input) == 0 && i == 0) ? ft_putendl(ft_pwd()): i++;
    (ft_strcmp("env", input) == 0 && i == 1) ? ft_envir(): i++;
    (ft_strcmp("exit", input) == 0 && i == 2) ? exit(1): i++;
    (ft_strcmp("cd", input) == 0 && i == 3) ? ft_cd("home"): i++;
    (ft_strlen(input) > 0 && i == 4) ? ft_execute_comand(av) : i++;
    i = 0;
}

void ft_process(void){
    char *input;
    
    while(1){
        ft_putstr("&> ");
        get_next_line(0, &input);
        (ft_elementcount(input, ' ') > 1) ? ft_options(input) : ft_nooptions(input);
        // free(input);
    }
}

int main(void) {
    ft_process();
    return 0;
}

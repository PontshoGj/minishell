#include "ft_minishell.h"

void ft_options(char *input){
    char **hold;

    hold = ft_strsplit(input, ' ');
    (ft_strcmp("cd" , hold[0]) == 0) ? ft_cd(hold[1]) : (void)0;
    (ft_strcmp("echo", hold[0]) == 0) ? ft_echo(input): (void)0;
    (ft_strcmp("setenv", hold[0]) == 0) ? ft_setenv(hold[1]): (void)0;
    (strcmp("unsetenv", hold[0]) == 0) ? ft_unsetenv(hold[1]): (void)0;
    (ft_strlen(input) > 0) ? ft_execute_comand(hold) : (void)0;
}

void ft_nooptions(char *input){
    char    **av;

    av = (char **)malloc(sizeof(char *) * 2);
    av[0] = input;
    av[1] = (char *)0;
    (ft_strcmp("pwd", input) == 0) ? ft_putendl(ft_pwd()): (void)0;
    (ft_strcmp("env", input) == 0) ? ft_envir(): (void)0;
    (ft_strcmp("exit", input) == 0) ? exit(1): (void)0;
    (ft_strcmp("cd", input) == 0) ? ft_cd("home"): (void)0;
    (ft_strlen(input) > 0) ? ft_execute_comand(av) : (void)0;
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

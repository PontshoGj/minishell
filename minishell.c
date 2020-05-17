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

void        ft_cleanup(){
    int     i;

    i = 0;
    while (store[i] != 0){
        ft_putendl(store[i]);
        if (store[i] != 0)
            free(store[i]);    
        i++;
    }
}

void ft_options(char *input){
    char **hold;
    int i;
    char *command;

    i = 0;
    command = ft_strtrim(ft_tebTospace(input));
    free(input);
    if (ft_strcmp(command,"") == 0)
    {
        free(command);
        return;
    }
    hold = ft_strsplit(command, ' ');
    // if (ft_strcmp("setenv", hold[0]) != 0 )
    //     ft_freearry(environment);
    (ft_strcmp("cd" , hold[0]) == 0 && i == 0) ? ft_cd(hold[1]) : i++;
    (ft_strcmp("echo", hold[0]) == 0 && i == 1) ? ft_echo(command): i++;
    (ft_strcmp("setenv", hold[0]) == 0 && i == 2) ? ft_setenv(hold[1]): i++;
    (ft_strcmp("unsetenv", hold[0]) == 0 && i == 3) ? ft_unsetenv(hold[1]): i++;
    (ft_strlen(command) > 0 && i == 4) ? ft_execute_comand(hold) : i++;
 if (ft_strcmp("setenv", hold[0]) != 0 )
        ft_freearry(hold);
    free(command);
    ft_cleanup();
}

void ft_nooptions(char **input){
    char    **av;
    int     i;
    char *pwds;
    char *command;

    i = 0;
    command = ft_strtrim(*input);
    free(*input);
    if (ft_strcmp(command,"") == 0){
        free(command);
        return;
    }
    av = (char **)malloc(sizeof(char *) * 2);
    av[0] = command;
    av[1] = NULL;
    pwds = ft_pwd();
    (ft_strcmp("pwd", command) == 0 && i == 0) ? ft_putendl(pwds): i++;
    free(pwds);
    (ft_strcmp("env", command) == 0 && i == 1) ? ft_envir(): i++;
    
    (ft_strcmp("cd", command) == 0 && i == 2) ? ft_cd("home"): i++;
    if (ft_strcmp("exit", command) == 0)
    {
        free(&av[0]);
        free(command);
        ft_cleanup();
        free(environment);
        exit(1);
    }
    (ft_strlen(command) > 0 && i == 3) ? ft_execute_comand(av) : i++;
    free(av);
    free(command);
    ft_cleanup();
}

void ft_process(void){
    char *input;
    
    input = 0;
    while(1){
        ft_putstr("&> ");
        get_next_line(0, &input);
        (ft_elementcount(input, ' ') > 1) ? ft_options(input) : ft_nooptions(&input); 
    }
}

char    **ft_strarrcpy(char **s){
    int i;
    char **new;

    i = 0;
    new = (char **)malloc(sizeof(char *) * (ft_strarrlen(s) + 1));
    while(s[i] != NULL){
        new[i] = s[i];//ft_strdup(s[i]);
        i++;
    }
    new[i] = NULL;
    return new;
}

int main(void) {
    environment = ft_strarrcpy(environ);
    ft_process();
    return 0;
}

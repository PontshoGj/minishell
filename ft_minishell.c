#include "ft_minishell.h"

void ft_process(void){
    char *input;
    char **hold;

    while(1){
        ft_putstr("&> ");
        get_next_line(0, &input);
        if (ft_elementcount(input, ' ') > 1){
            hold = ft_strsplit(input, ' ');
            if (ft_strcmp("cd" , hold[0]) == 0){
                ft_cd(hold[1]);
            }
            if (ft_strcmp("echo", hold[0]) == 0){
                ft_echo(input);
            }
            if (ft_strcmp("setenv", hold[0]) == 0){
                ft_setenv(hold[1]);
            }
            if (strcmp("unsetenv", hold[0]) == 0){
                ft_unsetenv(hold[1]);
            }
        }else{
            if (ft_strcmp("pwd", input) == 0){
                ft_putendl(ft_pwd());
            }
            if (ft_strcmp("env", input) == 0){
                ft_envir();
            }
            if (ft_strcmp("exit", input) == 0){
                exit(1);
            }
            if (ft_strcmp("cd", input) == 0){
                ft_cd("home");
            }
        }
        free(input);
    }
}

int main(void) {
    ft_process();
    return 0;
}

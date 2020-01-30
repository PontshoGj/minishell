#include "ft_minishell.h"


void ft_process(void){
    char *input;
    char **hold;


    ft_putstr("&> ");   

    while(1){
        get_next_line(0, &input);
        if (ft_elementcount(input, ' ') > 1){
            hold = ft_strsplit(input, ' ');
            if (ft_strcmp("cd" , hold[0]) == 0){
                // ft_putendl(hold[0]);
                ft_cd(hold[1]);
            }
            if (ft_strcmp("echo", hold[0]) == 0){
                ft_putendl(ft_strsub(input, ft_strlenc(input, ' ') + 1, ft_strlen(input)));
            }
            if (ft_strcmp("setenv", hold[0]) == 0){
                ft_setenv(hold[1]);
            }
        }else{
            if (ft_strcmp("pwd", input) == 0){
                ft_putendl(ft_pwd());
                // printf("%s\n", pwd());
            }
            if (ft_strcmp("env", input) == 0){
		        // int i = 0;
		        // while (environ[i] != 0)
			    //     ft_putendl(environ[i++]);
                 //ft_putendl(input);
                ft_envir();
            }
            if (ft_strcmp("exit", input) == 0){
                exit(1);
            }
            if (ft_strcmp("cd", input) == 0){
                ft_cd("home");
            }
        }
        ft_putstr("&> ");
        free(input);
    }
}

int main(void) {

    ft_process();
    return 0;
}

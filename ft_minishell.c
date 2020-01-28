#include "ft_minishell.h"


// void envir(char **opt){
//     execve("/bin/bash", opt, NULL);
// }

// char *pwd()
// {
//     char cwd[1024];
//     char *cwds = (char *)malloc(sizeof(char) * 1024);
//     getcwd(cwd, sizeof(cwd));
//     cwds = strcpy(cwds,cwd);
//     return (cwds);
// }

// void cd(char *s, char **env)
// {
//     char *var[2];

//     if (ft_strcmp("home", s) == 0 || ft_strcmp("~", s) == 0){
//         chdir(ft_strsub(env[23], 5, ft_strlen(env[23])));
//         var[0] = "HOME";
//         var[1] = ft_strsub(env[23], 5, ft_strlen(env[23]));
//         execve("/bin/setenv", var, NULL);
//     }else{
//         chdir(s);
//     }
// }


void ft_process(char **env){
    char *input;
    char **hold;


    ft_putstr("&> ");   

    while(1){
        get_next_line(0, &input);
        if (ft_elementcount(input, ' ') > 1){
            hold = ft_strsplit(input, ' ');
            if (ft_strcmp("cd" , hold[0]) == 0){
                // ft_putendl(hold[0]);
                ft_cd(hold[1], env);
            }
            if (ft_strcmp("echo", hold[0]) == 0){
                ft_putendl(hold[1]);
            }
        }else{
            if (ft_strcmp("pwd", input) == 0){
                ft_putendl(ft_pwd());
                // printf("%s\n", pwd());
            }
            if (ft_strcmp("env", input) == 0){
                 ft_putendl(input);
                ft_envir(0);
            }
            if (ft_strcmp("exit", input) == 0){
                exit(1);
            }
            if (ft_strcmp("cd", input) == 0){
                ft_cd("home", env);
            }
        }
        ft_putstr("&> ");
        free(input);
    }
}

int main(int ac,char **av,char **env) {
    (void)av;
    (void)ac;

    ft_process(env);
    return 0;
}
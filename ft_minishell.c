#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

#define  INPUT_STRING 1021

char *pwd()
{
    char cwd[1024];
    char *cwds = (char *)malloc(sizeof(char) * 1024);
    getcwd(cwd, sizeof(cwd));
    cwds = strcpy(cwds,cwd);
    return (cwds);
}

void cd(char *s)
{
    chdir(s);
}


void process(void){
    char s[INPUT_STRING] = {0};
    char *input;

    input = 0;

    ft_putstr("&> ");

    while(1){
        read(0, s, INPUT_STRING);
        input = ft_strtrim(s);
        // printf("%s", s);
        if (strcmp("pwd" ,input) == 0)
            printf("%s\n", pwd());
        else if (strcmp("cd", input) == 0){
            cd("../../Desktop");
        }

        // printf("%zu", strlen(s));
        // printf("%s\n", pwd());
    //     // cd(av[1]);
    //     // printf("%s\n", pwd());
    // free(input);
        ft_putstr("&> ");
    //     // exit(1);
    }
}

int main(void) {
    pid_t x;
    x = fork();
    if (x)
    {
        process();
    }else{
        exit(1);
    }
    wait(NULL);
    return 0;
}
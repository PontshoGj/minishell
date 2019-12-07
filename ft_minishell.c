#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int ac, char **av) {
    printf("%s\n", pwd());
    cd(av[1]);
    printf("%s\n", pwd());
    return 0;
}
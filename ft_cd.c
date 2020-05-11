#include "ft_minishell.h"

void pwd_oldpwd(char *newDir, char *oldDir)
{
    int i;

    i = 0;
    while(environ[i] != 0){
        if (ft_strcmp(ft_strsub(environ[i], 0, 7), "OLDPWD=") == 0){
            environ[i] = ft_strjoin("OLDPWD=", oldDir);
        }
        if (ft_strcmp(ft_strsub(environ[i], 0, 4), "PWD=") == 0){
            environ[i] = ft_strjoin("PWD=", newDir);
        }
        i++;
    }
     //free(&newDir);
    // free(&oldDir);
}

char *ft_envKey(char *dirs)
{
    char *envkey;
    int i;

    i = 0;
    envkey = 0;
    while(environ[i] != 0){
        if (ft_strstr(environ[i], dirs)){
            envkey = ft_strsub(environ[i], ft_strlen(dirs), ft_strlen(environ[i]));
        }
        i++;
    }
    return envkey;
}

void ft_cd(char *s)
{
    char *var;

    var = ft_pwd();
    if (ft_strcmp("home", s) == 0 || ft_strcmp("~", s) == 0){
        pwd_oldpwd(ft_envKey("HOME="), var);
        chdir(ft_envKey("HOME="));
    }else if (ft_strcmp("-", s) == 0)
    {
        chdir(ft_envKey("OLDPWD="));
        pwd_oldpwd(ft_pwd(), var);
    }else if (s[0] == '~' && s[1] == '/'){
        chdir(ft_strjoin(ft_envKey("HOME="),ft_strsub(s, 1, ft_strlen(s))));
        pwd_oldpwd(ft_pwd(), var);
    }
    else
    {
        if (chdir(s) != 0)
        {
            ft_putstr("cd: ");
            ft_putstr(s);
            ft_putendl(" : No such file or directory");
        }else{

            pwd_oldpwd(ft_pwd(), var);
        }
    }
}

#include "ft_minishell.h"

void pwd_oldpwd(char *newDir, char *oldDir)
{
    int i;
    char *envOldPwd;
    char *envPwd;
    
    envOldPwd = 0;
    envPwd = 0;
    i = 0;
    
    while(environ[i] != 0){
        envOldPwd = ft_strsub(environ[i], 0, 7);
        envPwd = ft_strsub(environ[i], 0, 4);
        if (ft_strcmp(envOldPwd, "OLDPWD=") == 0){
            if (ft_chectstore("OLDPWD") == 1)
                ft_delstore("OLDPWD");
            environ[i] = ft_strjoin("OLDPWD=", oldDir);
            ft_store("OLDPWD");
        }
        if (ft_strcmp(envPwd, "PWD=") == 0){
            if (ft_chectstore("PWD") == 1)
                ft_delstore("PWD");
            environ[i] = ft_strjoin("PWD=", newDir);
            ft_store("PWD");
        }
        i++;
        free(envOldPwd);
        free(envPwd);
    }
     free(newDir);
     free(oldDir);
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
            break;
        }
        i++;
    }
    return envkey;
}

void ft_cd(char *s)
{
    char *var;
    char *envHome;
    char *envOldPwd;
    
    envHome = ft_envKey("HOME=");
    envOldPwd = ft_envKey("OLDPWD=");
    var = ft_pwd();
    if (ft_strcmp("home", s) == 0 || ft_strcmp("~", s) == 0){
        pwd_oldpwd(envHome, var);
        envHome = ft_envKey("HOME=");
        chdir(envHome);
    }else if (ft_strcmp("-", s) == 0)
    {
        chdir(envOldPwd);
        pwd_oldpwd(ft_pwd(), var);
    }else if (s[0] == '~' && s[1] == '/'){
        chdir(ft_strjoin(envHome,ft_strsub(s, 1, ft_strlen(s))));
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
    free(envOldPwd);
    free(envHome);
}

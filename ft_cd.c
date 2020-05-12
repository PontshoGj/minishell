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
        if (ft_strcmp(/*ft_strsub(environ[i], 0, 7)*/ envOldPwd, "OLDPWD=") == 0){
            environ[i] = ft_strjoin("OLDPWD=", oldDir);
        }
        if (ft_strcmp(/*ft_strsub(environ[i], 0, 4)*/envPwd, "PWD=") == 0){
            environ[i] = ft_strjoin("PWD=", newDir);
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
        pwd_oldpwd(/*ft_envKey("HOME=")*/envHome, var);
        envHome = ft_envKey("HOME=");
        chdir(/*ft_envKey("HOME=")*/ envHome);
    }else if (ft_strcmp("-", s) == 0)
    {
        chdir(/*ft_envKey("OLDPWD=")*/envOldPwd);
        pwd_oldpwd(ft_pwd(), var);
    }else if (s[0] == '~' && s[1] == '/'){
        chdir(ft_strjoin(/*ft_envKey("HOME=")*/envHome,ft_strsub(s, 1, ft_strlen(s))));
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

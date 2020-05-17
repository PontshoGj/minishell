#include "ft_minishell.h"

void pwd_oldpwd(char *newDir, char *oldDir)
{
    char    *temp;
    
    ft_unsetenv("OLDPWD");
    temp = ft_strjoin("OLDPWD=", oldDir);
    ft_setenv(temp);
    free(temp);
    temp = 0;

    ft_unsetenv("PWD");
    temp = ft_strjoin("PWD=", newDir);
    ft_setenv(temp);
    free(temp);
}


void ft_cd(char *s)
{
    char *var;
    char *envHome;
    char *envOldPwd;
    char *temp;
    char    *temp2;
    
    temp = 0;
    temp2 = 0;
    envHome = ft_envKey("HOME=");
    envOldPwd = ft_envKey("OLDPWD=");
    var = ft_pwd();
    if (ft_strcmp("home", s) == 0 || ft_strcmp("~", s) == 0){
        pwd_oldpwd(envHome, var);
        chdir(envHome);
    }else if (ft_strcmp("-", s) == 0)
    {
        chdir(envOldPwd);
        temp = ft_pwd();
        pwd_oldpwd(temp, var);
        free(temp);
    }else if (s[0] == '~' && s[1] == '/'){
        temp2 = ft_strsub(s, 1, ft_strlen(s));
        temp = ft_strjoin(envHome,temp2);
        free(temp2);
        chdir(temp);
        free(temp);
        temp  = ft_pwd();
        pwd_oldpwd(temp, var);
        free(temp);
    }
    else
    {
        if (chdir(s) != 0)
        {
            ft_putstr("cd: ");
            ft_putstr(s);
            ft_putendl(" : No such file or directory");
        }else{
            temp = ft_pwd();
            pwd_oldpwd(temp, var);
            free(temp);
        }
    }
    free(var);
    free(envOldPwd);
    free(envHome);
}

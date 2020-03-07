#ifndef FT_MINISHELL
# define FT_MINISHELL

# include "libft/libft.h"
extern char **environ;

char    *ft_pwd();
void    ft_cd(char *s);
void    ft_envir();
void    ft_setenv(char *new_var);
void    ft_unsetenv(char *var);
int     ft_strarrlen(char **arr);
void    ft_echo(char *input);
void    ft_execute_comand(char **av);
#endif

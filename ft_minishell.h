#ifndef FT_MINISHELL
# define FT_MINISHELL

# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"
extern char **environ;
char        **store;
char        **n_environ;

size_t  ft_envKeys();
char  *ft_envKey(char *);
char    *ft_pwd();
void    ft_cd(char *s);
void    ft_envir();
void    ft_setenv(char *new_var);
void    ft_unsetenv(char *var);
int     ft_strarrlen(char **arr);
void    ft_echo(char *input);
void    ft_execute_comand(char **av);
void    ft_sighandler();
char    *ft_tabTospace(char *s);
#endif

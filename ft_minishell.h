#ifndef FT_MINISHELL
# define FT_MINISHELL

# include "libft/libft.h"
extern char **environ;
char        *store[1024];

char *ft_envKey(char *dirs);
char    *ft_pwd();
void    ft_cd(char *s);
void    ft_envir();
void    ft_setenv(char *new_var);
void    ft_unsetenv(char *var);
int     ft_strarrlen(char **arr);
void    ft_echo(char *input);
void    ft_execute_comand(char **av);
void    ft_store(char *s);
void    ft_delstore(char *s);
size_t    ft_chectstore(char *s);
#endif

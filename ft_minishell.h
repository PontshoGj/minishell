#ifndef FT_MINISHELL
# define FT_MINISHELL

# include "libft/libft.h"
extern char **environ;

char    *ft_pwd();
void    ft_cd(char *s);
void    ft_envir(char **opt);
#endif
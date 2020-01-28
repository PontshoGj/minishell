#ifndef FT_MINISHELL
# define FT_MINISHELL

# include "libft/libft.h"

char    *ft_pwd();
void    ft_cd(char *s, char **env);
void    ft_envir(char **opt);
#endif
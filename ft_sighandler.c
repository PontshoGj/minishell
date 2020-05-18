#include "ft_minishell.h"

void    ft_sighandler(int signum){
    if (signum == 2){
        ft_putstr("\n");
        ft_putstr("&> ");
    }
}
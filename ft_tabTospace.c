#include "ft_minishell.h"

char        *ft_tabTospace(char *s)
{
    int i;
    char    *temp;
    
    i = 0;
    temp = (char *)ft_memalloc(ft_strlen(s) + 1);
    while(s[i]){
        if (s[i] == '\t')
            temp[i] = ' ';
        else
            temp[i] = s[i];  
        i++;
    }
    temp[i] = 0;
	return temp;
}

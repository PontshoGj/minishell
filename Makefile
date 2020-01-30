NAME=ft_minishell.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -c -I .

RM=rm -f

<<<<<<< HEAD
SRC=ft_minishell.c ft_cd.c ft_envir.c ft_pwd.c ft_setenv.c ft_unsetenv.c ft_strarrlen.c ft_echo.c\
=======
SRC=ft_minishell.c ft_cd.c ft_envir.c ft_echo.c ft_pwd.c ft_setenv.c\
>>>>>>> 60a75f5958d1640640c47839003c6e9b86352b5c

OBJ=$(SRC:.c=.o)

$(NAME): 
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	$(CC) ft_minishell.c ft_minishell.a libft/libft.a 
	rm -f *.o
all: $(NAME)

clean:
	$(RM) $(OBJ) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

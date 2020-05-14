NAME=ft_minishell.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -c -I .

RM=rm -f

SRC=minishell.c ft_cd.c ft_envir.c ft_pwd.c ft_setenv.c ft_unsetenv.c ft_strarrlen.c ft_echo.c \
ft_execute_comand.c ft_store.c ft_delstore.c ft_checkstore.c \

OBJ=$(SRC:.c=.o)

$(NAME): 
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	$(CC) minishell.c ft_minishell.a libft/libft.a 
	$(RM) $(OBJ) *.o
all: $(NAME)

clean:
	$(RM) $(OBJ) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

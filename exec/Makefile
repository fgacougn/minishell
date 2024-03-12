SRC=ft_free_exec.c ft_echo.c ft_pwd.c ft_export.c ft_buildin.c ft_unset.c ft_env.c ft_exit.c ft_cd.c ft_varparse.c\
ft_add_char.c ft_add_vbi.c ft_add_var.c ft_varparse_line.c ft_build_export_plus.c ft_export_error.c\
ft_export_printe.c ft_execution.c ft_exec_access.c ft_exec_isbin.c
OBJ=$(SRC:.c=.o)
NAME=libexec.a
CC=cc
CFLAGS=-Wall -Werror -Wextra -g3

minishell : $(NAME)

$(NAME) : $(OBJ)
	ar r $(NAME) ../includes/exec.h $(OBJ)
	
all : $(OBJ)

%.o: %.c
	$(CC) -I../includes -o $@ -c $< $(CFLAGS)

clean :
	rm -f $(OBJ)

re : fclean $(NAME)

fclean : clean
	rm -f $(NAME)
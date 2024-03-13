SRC=main.c ft_get_shell.c ft_minishell.c ft_free_shell.c  ft_buildin_load.c ft_next_cmd.c
OBJ=$(SRC:.c=.o)
NAME=../minishell
CC=cc
CFLAGS=-Wall -Werror -Wextra -g3 -I../includes 
EXEC=../exec/exec.so
INCLUDES=-lexec -lu_parsing -lreadline -lft

$(NAME) : $(OBJ) libexec.a libft.a libu_parsing.a ../includes/exec.h ../includes/minishell.h ../includes/u_parsing.h ../includes/libft/libft.h
	$(CC) -I../includes  $(OBJ) $(CFLAGS) -L. $(INCLUDES) -o $(NAME)
	
%.o: %.c ../includes/exec.h ../includes/minishell.h ../includes/u_parsing.h ../includes/libft/libft.h
	$(CC) -o $@ -c $< $(CFLAGS)

../includes/exec.h : 
	make libexec.a

../includes/u_parsing.h :
	make libu_parsing.a

../includes/libft/libft.h :
	make libft.a

libparsing.a :
	make -C ../parsing
	cp ../parsing/libparsing.a libparsing.a

libu_parsing.a :
	echo coucou
	make -C ../u_parse
	cp ../u_parse/libu_parsing.a libu_parsing.a

libexec.a :
	make -C ../exec
	cp ../exec/libexec.a libexec.a

libft.a : ../libft.a

../libft.a :
	make -C ../includes/libft
	cp ../includes/libft/libft.a libft.a

clean :
	rm -f $(OBJ) libexec.a libparsing.a libft.a libu_parsing.a

re : fclean $(NAME)

fclean : clean

SRC=ft_and.c ft_uparsing.c ft_lst_new_cmd.c ft_cmd.c ft_less.c ft_more.c ft_pipe.c ft_openpar.c\
ft_closepar.c ft_semicol.c ft_cpt_words.c ft_lst_flush_cmd.c ft_lst_free_cmd.c ft_get_endarg.c\
ft_free_uparse.c ft_lst_print_cmd.c ft_closeinfile.c ft_here_doc.c  ft_read_hdoc.c\
ft_uparse_setup.c ft_get_buildin.c
OBJ=$(SRC:.c=.o)
NAME=libu_parsing.a
CC=cc
CFLAGS=-Wall -Werror -Wextra -g3

minishell : $(NAME)

$(NAME) : $(OBJ) Makefile
	ar r $(NAME) ../includes/u_parsing.h $(OBJ)
	
all : $(OBJ)

%.o: %.c Makefile
	$(CC) -I../includes -o $@ -c $< $(CFLAGS)

clean :
	rm -f $(OBJ)

re : fclean $(NAME)

fclean : clean
	rm -f $(NAME)
	
#bash --posix
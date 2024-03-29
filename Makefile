NAME=minishell

$(NAME) : ../includes/exec.h ../includes/libft/libft.h ../includes/u_parsing.h ../includes/minishell.h
	 make -C kernel

../includes/exec.h :
	#  make -C exec

../includes/minishell.h :
	#  make clean -C kernel

../includes/u_parsing.h :
	#  make -C u_parse

../includes/libft/libft.h :
	#  make -C includes/libft

clean : 
	 make clean -C includes/libft
	 make clean -C exec
	 make clean -C u_parse
	 make clean -C kernel
	 
fclean :
	 make fclean -C includes/libft
	 make fclean -C exec
	 make fclean -C u_parse
	 make fclean -C kernel
	 rm -f $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean 
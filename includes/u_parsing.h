/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_parsing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:58:33 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 11:37:31 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_PARSING_H
# define U_PARSING_H

# define DEVIDERS "<>|()&;"
# define NB_PARSE 8

typedef struct s_here_line
{
	char			*line;
	struct s_line	*next;
}					t_here_line;

typedef struct s_cmd
{
	char			**argv;
	int				isinfile;
	char			*str_infile;
	int				fd_infile;
	int				isoutfile;
	char			*str_outfile;
	int				fd_outfile;
	int				pipeout;
	int				pipein;
	int				heredoc;
	char			*limiter;
	int				buildin;
	t_here_line		*here_lines;
	t_here_line		*last;
	char			**arglines;
	struct s_cmd	*next;
	struct s_cmd	*dep;
	struct s_cmd	*from;
}					t_cmd;

typedef struct s_u_parsing
{
	char			*line;
	char			*start;
	int				cpt_words;
	int				i_words;
	int				token;
	int				err;
	int				i;
	char			*p_parse;
	int				(*f_parse[NB_PARSE])(void);
	t_cmd			*current;
	t_cmd			*tofree;
	t_cmd			*first;
	t_cmd			*last;
}					t_u_parsing;

int					ft_uparsing(void);
int					ft_less(void);
int					ft_more(void);
int					ft_pipe(void);
int					ft_openpar(void);
int					ft_closepar(void);
int					ft_and(void);
int					ft_semicol(void);
int					ft_cmd(void);
int					ft_lst_new_cmd(void);
int					ft_cpt_words(void);
int					ft_lst_flush_cmd(void);
int					ft_lst_free_cmd(void);
int					ft_get_endarg(void);
int					ft_free_uparse(void);
int					ft_here_doc(void);
int					ft_closeinfile(void);
int					ft_read_hdoc(void);
int					ft_lst_print_cmd(t_cmd *command);
int					ft_uparse_setup(void);
int					ft_get_buildin(void);

#endif
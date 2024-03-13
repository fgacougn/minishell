/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:08:25 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 12:15:28 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "exec.h"
# include "libft/libft.h"
# include "u_parsing.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

# define MINIPROMPT "minishell>"
# define MS_NOBI -1
# define MS_ECHO 0
# define MS_PWD 1
# define MS_ENV 2
# define MS_UNSET 3
# define MS_EXPORT 4
# define MS_EXIT 5
# define MS_CD 6

# define OPT_PIPIN 1
# define OPT_PIPOUT 2
# define HERE_DOC 4
# define TRUERET 8

typedef struct s_minishell
{
	t_u_parsing	u;
	t_exec		e;
	int			argc;
	char		**argv;
	char		**env;
	char		**tabenv;
	int			ret;
}				t_minishell;

t_minishell		*ft_get_shell(void);
void			ft_free_shell(void) __attribute__((destructor));
t_minishell		*s(void);
void			ft_minishell(void);
int				ft_buildin_load(void) __attribute__((constructor));
int				ft_next_cmd(void);
#endif
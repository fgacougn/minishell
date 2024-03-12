/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:09:30 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/08 16:33:41 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/types.h>
# include <sys/wait.h>

# define MAX_PATH 2000
# define VAR_ESC "=!;\'|\"<>*()&-@$#%^+[],./{}:<>?"
# define VAR_BI "0123456789-@#$_?"

typedef struct s_load
{
	char			*cmd_tab[16384];
	char			**tabenv;
	int				status;
	int				opt;
	char			*input;
	char			*output;
	char			*err;
	char			*infile;
	char			*outfile;
	int				buildin;
}					t_load;

typedef struct s_child
{
	pid_t			pid;
	struct s_child	*next;
}					t_child;

typedef struct s_exec
{
	t_load			loading;
	char			*binpath;
	char			*line;
	int				buildin;
	int				ret_val;
	int				argc;
	char			**argv;
	char			**env;
	char			**exec_argv;
	char			**iter_exec;
	char			**exec_env;
	int				fd_out;
	int				file_close;
	int				echo_n;
	char			*pwd;
	int				exec_bool;
	char			*tempchar;
	char			*temp1;
	char			*temp2;
	char			*temp3;
	char			*temp4;
	long long int	exec_index;
	int				exit;
	int				cpt;
	int				cpts;
	char			*exec_line;
	int				isdequote;
	int				(*f_buildin[7])(void);
	char			cwd[MAX_PATH];
	char			cwd2[MAX_PATH];
	int				piped[2][2];
	int				lastpipe;
	int				*pipin;
	int				*pipout;
	int				dolquestionmark;
	char			**envp;
	char			**path;
	char			**exec_path;
	pid_t			child;
	t_child			*first;
	t_child			*last;
	t_child			*current;
	t_child			*local;
}					t_exec;

int					ft_free_exec(void);

int					ft_buildin(void);
int					ft_echo(void);
int					ft_pwd(void);
int					ft_export(void);
int					ft_unset(void);
int					ft_exit(void);
int					ft_cd(void);
int					ft_env(void);
int					ft_varparse(void);
int					ft_add_char(void);
int					ft_add_vbi(void);
int					ft_add_var(void);
int					ft_build_export_plus(void);
int					ft_export_error(void);
int					ft_export_printe(void);
int					ft_acess_printe(void);
int					ft_execution(void);
int					ft_exec_access(void);
int					ft_exec_isbin(void);
int					ft_exec_printe(void);

// load pointeur to the char * in e.exec_argv
int					ft_varparse_line(void);

#endif

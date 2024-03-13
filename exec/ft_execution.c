/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:30:40 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 12:44:08 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*appeler fonction pour ouvrir les fichiers dans le child process,
	si ca retourne une erreur, tu retourne la valeur d'erreur associee,
		les fichiers se trouvent dans s()->p.infile, s()->p.outfile,
			s()->is_heredoc == 1
	check_if_isatty
		infile token =TK_INPUT
		outfile token = TK_OUTPUT
		here_doc token = TK_DLMTR

		retour enfant sur s()->e.dolquestionmark;
		*/

int	ft_execution(void)
{
	printf("execution\n");
	if (!s()->u.current)
		return (SUCCESS);
	s()->e.argv = s()->u.current->argv;
	if (s()->e.argv == 0)
		return (SUCCESS);
	ft_varparse();
	if (s()->u.current->buildin > MS_ENV)
	{
		s()->e.f_buildin[s()->u.current->buildin]();
	}
	else if (ft_exec_access() == SUCCESS || s()->u.current->buildin != MS_NOBI)
	{
		s()->e.buildin = s()->u.current->buildin;
		// s()->e.ret_val = ft_exec_access();
		// if (s()->e.ret_val != SUCCESS)
		// 	return (s()->e.ret_val);
		// // if (s()->p.pipe)
		// // 	if (open_pipes(&s()->p.s, s()->p.f))
		// // 		return (ERR_PARS);
		// // s()->e.argv = s()->e.loading.cmd_tab;
		// // s()->e.argc = ft_split_cpt(s()->e.argv);
		// // s()->e.env = s()->e.loading.tabenv;
		// // s()->e.buildin = s()->e.loading.buildin;
		s()->e.child = fork();
		if (s()->e.child == 0)
		{
			printf("forked %s\n", s()->e.binpath);
			// 	// 	if (s()->e.loading.opt & OPT_PIPIN)
			// 	// 	{
			// 	// 		s()->e.pipin = s()->e.piped[s()->e.lastpipe];
			// 	// 		if (dup2(STDIN_FILENO, s()->e.pipin[1]) < 0)
			// 	// 			return (ERR_DUP);
			// 	// 		close(s()->e.pipin[0]);
			// 	// 		close(s()->e.pipin[1]);
			// 	// 	}
			// 	// 	if (s()->e.loading.opt & OPT_PIPOUT)
			// 	// 	{
			// 	// 		s()->e.lastpipe++;
			// 	// 		s()->e.pipout = s()->e.piped[s()->e.lastpipe];
			// 	// 		if (pipe(s()->e.pipout) == -1)
			// 	// 		{
			// 	// 			perror(s()->e.argv[0]);
			// 	// 			return (ERR_PIPE);
			// 	// 		}
			// 	// 		if (dup2(STDOUT_FILENO, s()->e.pipout[0]) < 0)
			// 	// 			return (ERR_DUP);
			// 	// 		close(s()->e.pipout[0]);
			// 	// 		close(s()->e.pipout[1]);
			// 	// 	}
			printf("exec infile %d outfile %d fd %d\n",
				s()->u.current->isinfile, s()->u.current->isoutfile,
				s()->u.current->fd_outfile);
			if (s()->u.current->isinfile)
			{
				if (dup2(s()->u.current->fd_infile, STDIN_FILENO) == -1)
					return (ERR_DUP);
			}
			if (s()->u.current->isoutfile)
			{
				if (dup2(s()->u.current->fd_outfile, STDOUT_FILENO) == -1)
					return (ERR_DUP);
				printf("dupout\n");
			}
			if (s()->e.buildin != MS_NOBI)
			{
				ft_printf("isbuildin\n");
				s()->e.f_buildin[s()->e.buildin]();
			}
			else
			{
				execve(s()->e.binpath, s()->e.argv, s()->e.env);
				printf("path %s\n", s()->e.binpath);
				ft_printf_split(s()->e.argv);
				ft_printf_split(s()->e.env);
				ft_puterror("\033[1;31m");
				perror("Minishell");
				ft_puterror("\033[0m");
			}
			s()->e.argv = 0;
			exit(0);
			// 	// s()->p.s.status = BREAK;
			// 	// 	s()->e.exit = 1;
			// 	// 	return (SUCCESS);
		}
		else if (s()->e.child < 0)
		{
			if (s()->e.binpath)
			{
				free(s()->e.binpath);
				s()->e.binpath = 0;
			}
			s()->e.temp1 = 0;
			return (ERR_FORK);
		}
		wait(0);
		// // if (s()->e.loading.opt & OPT_PIPIN)
		// // {
		// // 	s()->e.pipin = s()->e.piped[s()->e.lastpipe];
		// // 	close(s()->e.pipin[0]);
		// // 	close(s()->e.pipin[1]);
		// // }
		// // if (s()->e.loading.opt & OPT_PIPOUT)
		// // 	s()->e.lastpipe++;
		if (s()->e.binpath)
		{
			free(s()->e.binpath);
			s()->e.binpath = 0;
		}
		s()->e.temp1 = 0;
	}
	s()->e.argv = 0;
	ft_next_cmd();
	return (ft_execution());
}
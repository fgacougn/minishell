/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:10:25 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 17:38:55 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lst_print_cmd(t_cmd *command)
{
	static int number;
	int localnum;

	if (!command)
		return (SUCCESS);
	localnum = number++;
	ft_printf("command %d\n", localnum);
	ft_printf_split(command->argv);
	ft_printf("infile %d char %s fd %d\n", command->isinfile, command->str_infile,
		command->fd_infile);
	ft_printf("outfile %d char %s fd %d\n", command->isoutfile,
		command->str_outfile, command->fd_outfile);
	ft_printf("pipein %d piepout %d\n", command->pipein, command->pipeout);
	ft_printf("heredoc %d limiter %s\n", command->heredoc, command->limiter);
	ft_printf("dep command %d P %p\n", localnum, command->dep);
	ft_lst_print_cmd(command->dep);
	ft_printf("next command %d P %p\n", localnum, command->next);
	ft_lst_print_cmd(command->next);
	ft_printf("end command %d\n", localnum);
	return (SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:40:50 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 12:48:03 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(void)
{
	if (!s()->e.argv)
		return (ERR_BAD_PNTR);
	s()->e.exec_argv = s()->e.argv;
	if (ft_strncmp(*(s()->e.exec_argv), "echo", 5))
		return (ERR_BAD_ARGS);
	s()->e.exec_argv++;
	if (!*s()->e.exec_argv)
		return (ERR_BAD_ARGS);
	while (!ft_strncmp(*(s()->e.exec_argv), "-n", 3))
	{
		s()->e.echo_n = 1;
		s()->e.exec_argv++;
	}
	while (*(s()->e.exec_argv))
	{
		ft_putstr_fd(*(s()->e.exec_argv), s()->e.fd_out);
		if (!*(s()->e.exec_argv + 1))
		{
			break ;
		}
		s()->e.exec_argv++;
		if (*(s()->e.exec_argv))
			ft_putchar_fd(' ', s()->e.fd_out);
	}
	if (s()->e.echo_n)
	{
		if (*(s()->e.exec_argv) != 0 && *(*(s()->e.exec_argv)) != 0)
		{
			s()->e.tempchar = *(s()->e.exec_argv);
			while (*(s()->e.tempchar + 1) != 0)
				s()->e.tempchar = s()->e.tempchar + 1;
		}
		// if (*(s()->e.tempchar) != '\n')
		// {
		// 	ft_putstr_fd("\e[0;30m\e[47m%\033[0m", s()->e.fd_out);
		// }
		s()->e.echo_n = 0;
	}
	else
		ft_putchar_fd('\n', s()->e.fd_out);
	return (SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:01:16 by fgacougn          #+#    #+#             */
/*   Updated: 2024/02/02 11:35:07 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(void)
{
	if (!s()->e.argv)
		return (ERR_BAD_PNTR);
	s()->e.exec_argv = s()->e.argv;
	if (ft_strncmp(*(s()->e.exec_argv), "cd", 3))
		return (ERR_BAD_ARGS);
	s()->e.exec_argv++;
	if (!*s()->e.exec_argv)
		return (ERR_BAD_ARGS);
	getcwd(s()->e.cwd2, MAX_PATH);
	chdir(*s()->e.exec_argv);
	getcwd(s()->e.cwd, MAX_PATH);
	s()->e.tempchar = ft_strbuild("export PWD=", s()->e.cwd, " OLDPWD=",
			s()->e.cwd2);
	if (!s()->e.tempchar)
		return (ERR_MALLOC);
	ft_free_split(s()->e.argv);
	s()->e.argv = ft_split(s()->e.tempchar, ' ');
	free(s()->e.tempchar);
	ft_export();
	return (SUCCESS);
}
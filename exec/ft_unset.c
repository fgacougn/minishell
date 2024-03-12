/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:59:15 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/11 13:28:23 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(void)
{
	if (!s()->e.argv)
		return (ERR_BAD_PNTR);
	s()->e.exec_argv = s()->e.argv;
	if (ft_strncmp(*(s()->e.exec_argv), "unset", 6))
		return (ERR_BAD_ARGS);
	s()->e.exec_argv++;
	while (*(s()->e.exec_argv))
	{
		s()->e.tempchar = ft_strbuild(*(s()->e.exec_argv), "=", 0, 0);
		if (!s()->e.tempchar)
			return (ERR_MALLOC);
		s()->e.exec_env = ft_splitcpy_minus(s()->e.env, s()->e.tempchar);
		if (!s()->e.exec_env)
		{
			free(s()->e.tempchar);
			return (ERR_MALLOC);
		}
		if (s()->e.env != s()->e.exec_env)
			ft_free_split(s()->e.env);
		s()->e.env = s()->e.exec_env;
		free(s()->e.tempchar);
		s()->e.exec_argv++;
	}
	if (!*s()->e.exec_argv)
		return (ERR_BAD_ARGS);
	return (SUCCESS);
}
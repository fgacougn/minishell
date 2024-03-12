/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_export_plus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:49:32 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/06 18:14:21 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_build_export_plus(void)
{
	printf("EXPORT +\n");
	s()->e.temp1 = ft_strndup(*s()->e.exec_argv, s()->e.exec_index - 1);
	if (*s()->e.iter_exec)
		s()->e.temp2 = ft_strdup(&((*s()->e.iter_exec)[s()->e.exec_index + 1]));
	s()->e.temp3 = ft_strdup(&((*s()->e.exec_argv)[s()->e.exec_index + 2]));
	s()->e.temp4 = ft_strbuild(s()->e.temp1, "=", s()->e.temp2, s()->e.temp3);
	if (!s()->e.temp1 || (!s()->e.temp2 && *s()->e.iter_exec) || !s()->e.temp3
		|| !s()->e.temp4)
	{
		if (s()->e.temp1)
		{
			free(s()->e.temp1);
			s()->e.temp1 = 0;
		}
		if (s()->e.temp2)
		{
			free(s()->e.temp2);
			s()->e.temp2 = 0;
		}
		if (s()->e.temp3)
		{
			free(s()->e.temp3);
			s()->e.temp3 = 0;
		}
		if (s()->e.temp4)
		{
			free(s()->e.temp4);
			s()->e.temp4 = 0;
		}
		return (ERR_MALLOC);
	}
	free(*s()->e.exec_argv);
	if (s()->e.temp1)
	{
		free(s()->e.temp1);
		s()->e.temp1 = 0;
	}
	if (s()->e.temp2)
	{
		free(s()->e.temp2);
		s()->e.temp2 = 0;
	}
	if (s()->e.temp3)
	{
		free(s()->e.temp3);
		s()->e.temp3 = 0;
	}
	*s()->e.exec_argv = s()->e.temp4;
	s()->e.temp4 = 0;
	return (SUCCESS);
}
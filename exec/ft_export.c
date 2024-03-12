/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:17:37 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/08 14:29:07 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// export A=2 B+=5 C=12 D+=3 D+=12

int	ft_export(void)
{
	if (!s()->e.argv)
		return (ERR_BAD_PNTR);
	s()->e.exec_argv = s()->e.argv;
	if (ft_strncmp(*(s()->e.exec_argv), "export", 7))
		return (ERR_BAD_ARGS);
	s()->e.exec_argv++;
	while (*s()->e.exec_argv)
	{
		s()->e.ret_val = ft_export_error();
		if (s()->e.ret_val == ERR_MALLOC)
			return (ERR_MALLOC);
		if (s()->e.ret_val == SUCCESS)
		{
			s()->e.exec_bool = 0;
			s()->e.iter_exec = s()->e.env;
			while (*s()->e.iter_exec)
			{
				s()->e.exec_index = ft_strchr(*s()->e.iter_exec, '=')
					- *s()->e.iter_exec;
				if (s()->e.exec_index >= 0 && ft_strncmp(*s()->e.exec_argv,
						*s()->e.iter_exec, (int)s()->e.exec_index) == 0)
				{
					s()->e.exec_bool = 1;
					break ;
				}
				s()->e.iter_exec++;
			}
			// printf("EXPORT %lld %c %s // %s\n", s()->e.exec_index,
			// 	(*s()->e.exec_argv)[s()->e.exec_index], *s()->e.iter_exec,
			// 	*s()->e.exec_argv);
			if (s()->e.exec_bool == 1
				&& (*s()->e.exec_argv)[s()->e.exec_index] == '+')
				ft_build_export_plus();
			if (s()->e.exec_bool == 0)
			{
				s()->e.temp1 = ft_strchr(*s()->e.exec_argv, '+');
				if (s()->e.temp1)
				{
					printf("no  found %s\n", s()->e.temp1);
					s()->e.exec_index = s()->e.temp1 - *s()->e.exec_argv;
					s()->e.temp1 = 0;
					if (s()->e.exec_index != 0)
						ft_build_export_plus();
				}
				else
					s()->e.temp1 = 0;
			}
			if (s()->e.exec_bool == 0)
			{
				s()->e.exec_env = ft_splitcpy_plus(s()->e.env,
						*s()->e.exec_argv);
				if (s()->e.exec_env == 0)
					return (ERR_MALLOC);
				ft_free_split(s()->e.env);
				s()->e.env = s()->e.exec_env;
			}
			else
			{
				s()->e.tempchar = ft_strdup(*s()->e.exec_argv);
				if (!s()->e.tempchar)
					return (ERR_MALLOC);
				free(s()->e.iter_exec[0]);
				s()->e.iter_exec[0] = s()->e.tempchar;
			}
		}
		s()->e.exec_argv++;
	}
	return (SUCCESS);
}
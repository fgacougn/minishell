/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:38:15 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/11 11:12:42 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_access(void)
{
	if (!s()->e.env)
		return (ERR_BAD_PNTR);
	// printf("inaccess\n");
	s()->e.envp = ft_get_envp(s()->e.env);
	if (!s()->e.envp)
		return (ERR_MALLOC);
	if (s()->e.envp[ENVP_PATH])
	{
		s()->e.path = ft_split(s()->e.envp[ENVP_PATH], ':');
		if (!s()->e.path)
		{
			free(s()->e.envp);
			s()->e.envp = 0;
			return (ERR_MALLOC);
		}
		s()->e.exec_path = s()->e.path;
		// ft_printf_split(s()->e.path);
		while (*s()->e.exec_path)
		{
			// printf("ptr %p str %s\n", s()->e.exec_path, *s()->e.exec_path);
			s()->e.binpath = *s()->e.exec_path;
			s()->e.ret_val = ft_exec_isbin();
			// printf("retval %d\n", s()->e.ret_val);
			s()->e.binpath = 0;
			if (s()->e.ret_val == ERR_MALLOC)
			{
				ft_free_split(s()->e.path);
				free(s()->e.envp);
				s()->e.envp = 0;
				return (ERR_MALLOC);
			}
			else if (s()->e.ret_val == ERR_BAD_FILE)
			{
				ft_free_split(s()->e.path);
				free(s()->e.envp);
				s()->e.envp = 0;
				ft_exec_printe();
				return (ERR_BAD_FILE);
			}
			else if (s()->e.ret_val == SUCCESS)
			{
				s()->e.binpath = s()->e.temp1;
				s()->e.temp1 = 0;
				ft_free_split(s()->e.path);
				free(s()->e.envp);
				s()->e.envp = 0;
				return (SUCCESS);
			}
			s()->e.exec_path++;
		}
		s()->e.binpath = 0;
		s()->e.ret_val = ft_exec_isbin();
		// printf("retval %d\n", s()->e.ret_val);
		if (s()->e.ret_val == ERR_MALLOC)
		{
			ft_free_split(s()->e.path);
			free(s()->e.envp);
			s()->e.envp = 0;
			return (ERR_MALLOC);
		}
		else if (s()->e.ret_val == ERR_BAD_FILE)
		{
			ft_free_split(s()->e.path);
			free(s()->e.envp);
			s()->e.envp = 0;
			ft_exec_printe();
			return (ERR_BAD_FILE);
		}
		else if (s()->e.ret_val == SUCCESS)
		{
			s()->e.binpath = s()->e.temp1;
			s()->e.temp1 = 0;
			ft_free_split(s()->e.path);
			free(s()->e.envp);
			s()->e.envp = 0;
			return (SUCCESS);
		}
		ft_free_split(s()->e.path);
	}
	ft_acess_printe();
	free(s()->e.envp);
	s()->e.envp = 0;
	return (ERR_BAD_ARGS);
}
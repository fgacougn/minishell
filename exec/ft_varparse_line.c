/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varparse_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:03:48 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/06 14:14:54 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_varparse_line(void)
{
	s()->e.cpt = 0;
	s()->e.cpts = 0;
	s()->e.isdequote = 0;
	s()->e.exec_line = *(s()->e.exec_argv);
	// printf("test /%s/ %d\n", *(s()->e.exec_argv),
	// 	s()->e.exec_line[s()->e.cpt] && s()->e.ret_val == SUCCESS);
	while (s()->e.exec_line[s()->e.cpt] && s()->e.ret_val == SUCCESS)
	{
		if (s()->e.exec_line[s()->e.cpt] == '\'' && s()->e.isdequote)
			s()->e.isdequote = 0;
		else if (s()->e.exec_line[s()->e.cpt] == '\'')
			s()->e.isdequote = 1;
		else if (s()->e.isdequote == 0)
		{
			if (s()->e.exec_line[s()->e.cpt] == '"')
			{
				s()->e.cpt -= 1;
				s()->e.ret_val = ft_add_char();
				if (s()->e.ret_val != SUCCESS)
					return (ERR_MALLOC);
				s()->e.cpt += 1;
				s()->e.cpts = s()->e.cpt + 1;
			}
			else if (s()->e.exec_line[s()->e.cpt] == '$')
			{
				// printf("ici %d %d\n", ft_is_in(VAR_BI,
				// s()->e.exec_line[s()->e.cpt + 1]) != -1, );
				if (ft_is_in(VAR_BI, s()->e.exec_line[s()->e.cpt + 1]) != -1)
				{
					s()->e.cpt -= 1;
					s()->e.ret_val = ft_add_char();
					s()->e.cpt += 1;
					if (s()->e.ret_val == SUCCESS)
						s()->e.ret_val = ft_add_vbi();
					if (s()->e.ret_val != SUCCESS)
						return (ERR_MALLOC);
				}
				else if (ft_is_in(VAR_ESC, s()->e.exec_line[s()->e.cpt + 1]) ==
					-1)
				{
					s()->e.cpt -= 1;
					s()->e.ret_val = ft_add_char();
					s()->e.cpt += 1;
					s()->e.cpts = ++s()->e.cpt;
					if (s()->e.ret_val == SUCCESS)
						s()->e.ret_val = ft_add_var();
					if (s()->e.ret_val != SUCCESS)
						return (ERR_MALLOC);
				}
			}
		}
		s()->e.cpt++;
	}
	// printf("OUT %d %d\n", s()->e.cpt, s()->e.cpts);
	s()->e.ret_val = ft_add_char();
	if (s()->e.ret_val != SUCCESS)
		return (ERR_MALLOC);
	// printf("%d %d\n", s()->e.ret_val, SUCCESS);
	free(*s()->e.exec_argv);
	*(s()->e.exec_argv) = ft_strbuild(s()->e.temp1, s()->e.temp2, s()->e.temp3,
			s()->e.temp4);
	// printf("1 %s 2 %s 3 %s 4%s\n", s()->e.temp1, s()->e.temp2,
	// s()->e.temp3,
	// 	s()->e.temp4);
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
	if (!*(s()->e.exec_argv))
		s()->e.ret_val = ERR_MALLOC;
	// printf("after /%s/\n", *(s()->e.exec_argv));
	return (SUCCESS);
}
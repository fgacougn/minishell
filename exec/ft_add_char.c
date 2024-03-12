/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:19:07 by fgacougn          #+#    #+#             */
/*   Updated: 2024/02/21 12:21:40 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_char(void)
{
	// printf("IN %d %d\n", s()->e.cpt, s()->e.cpts);
	if (s()->e.cpt <= s()->e.cpts )
		return (SUCCESS);
	if (!s()->e.temp1)
	{
		s()->e.temp1 = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.temp1);
		if (!s()->e.temp1)
			return (ERR_MALLOC);
	}
	else if (!s()->e.temp2)
	{
		s()->e.temp2 = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.temp2);
		if (!s()->e.temp2)
			return (ERR_MALLOC);
	}
	else if (!s()->e.temp3)
	{
		s()->e.temp3 = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.temp3);
		if (!s()->e.temp3)
			return (ERR_MALLOC);
	}
	else if (!s()->e.temp4)
	{
		s()->e.temp4 = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.temp4);
		if (!s()->e.temp4)
			return (ERR_MALLOC);
		s()->e.tempchar = ft_strbuild(s()->e.temp1, s()->e.temp2, s()->e.temp3,
				s()->e.temp4);
		if (!s()->e.tempchar)
			return (ERR_MALLOC);
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
		s()->e.temp1 = s()->e.tempchar;
		s()->e.tempchar = 0;
	}
	return (SUCCESS);
}
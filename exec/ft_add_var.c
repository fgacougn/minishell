/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:28:01 by fgacougn          #+#    #+#             */
/*   Updated: 2024/02/21 12:21:46 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_var(void)
{
	// printf("addvar %d %d\n", s()->e.cpt, s()->e.cpts);
	while ((*s()->e.exec_argv)[s()->e.cpt] && ft_is_in(VAR_ESC,
			(*s()->e.exec_argv)[s()->e.cpt]) == -1)
		(s()->e.cpt)++;
	(s()->e.cpt)--;
	// printf("%c\n", (*s()->e.exec_argv)[s()->e.cpt]);
	if (!s()->e.temp1)
	{
		s()->e.tempchar = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.tempchear);
		if (!s()->e.tempchar)
			return (ERR_MALLOC);
		s()->e.temp1 = ft_hach_find(s()->e.tempchar, s()->e.env);
		if(s()->e.tempchar)
		{
			free(s()->e.tempchar);
			s()->e.tempchar = 0;
		}
		// printf("1 %s\n", s()->e.temp1);
		// if (!s()->e.temp1)
		// {
		// 	free(s()->e.tempchar);
		// 	s()->e.tempchar = 0;
		// 	return (ERR_MALLOC);
		// }
	}
	else if (!s()->e.temp2)
	{
		s()->e.tempchar = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.tempchar);
		if (!s()->e.tempchar)
			return (ERR_MALLOC);
		s()->e.temp2 = ft_hach_find(s()->e.tempchar, s()->e.env);
		if(s()->e.tempchar)
		{
			free(s()->e.tempchar);
			s()->e.tempchar = 0;
		}
		// printf("2 %s\n", s()->e.temp2);
		// if (!s()->e.temp2)
		// {
		// 	free(s()->e.tempchar);
		// 	s()->e.tempchar = 0;
		// 	return (ERR_MALLOC);
		// }
	}
	else if (!s()->e.temp3)
	{
		s()->e.tempchar = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.tempchar);
		if (!s()->e.tempchar)
			return (ERR_MALLOC);
		s()->e.temp3 = ft_hach_find(s()->e.tempchar, s()->e.env);
		if(s()->e.tempchar)
		{
			free(s()->e.tempchar);
			s()->e.tempchar = 0;
		}
		// printf("3 %s\n", s()->e.temp3);
		// if (!s()->e.temp3)
		// {
		// 	free(s()->e.tempchar);
		// 	s()->e.tempchar = 0;
		// 	return (ERR_MALLOC);
		// }
	}
	else if (!s()->e.temp4)
	{
		s()->e.tempchar = ft_strndup(&((*s()->e.exec_argv)[s()->e.cpts]),
				s()->e.cpt - s()->e.cpts);
		// printf("ret %s\n", s()->e.tempchar);
		if (!s()->e.tempchar)
			return (ERR_MALLOC);
		s()->e.temp4 = ft_hach_find(s()->e.tempchar, s()->e.env);
		if(s()->e.tempchar)
		{
			free(s()->e.tempchar);
			s()->e.tempchar = 0;
		}
		// printf("4 %s\n", s()->e.temp4);
		// if (!s()->e.temp4)
		// {
		// 	free(s()->e.tempchar);
		// 	s()->e.tempchar = 0;
		// 	return (ERR_MALLOC);
		// }
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
	s()->e.cpts = s()->e.cpt + 1;
	return (SUCCESS);
}